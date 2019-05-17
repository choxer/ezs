#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include "queue.h"
#include "process.h"
#include "processmodel.h"



static pctx *context;

void sig_block() {
	p_switch_blocked(context->running);
	q_add(context->qblocked, context->running);
}

int main() {

	context = malloc(sizeof(context));
    if(!context) return 1;

    context->qready = malloc(sizeof(queue));
    context->qready->start = NULL;
    context->qready->end   = NULL;

    context->qblocked = malloc(sizeof(queue));
    context->qblocked->start = NULL;
    context->qblocked->end   = NULL;
    
	process *proc = malloc(10*sizeof(process));

    sigset_t set;
    sigfillset(&set);
    struct sigaction st;
    memset(&st,0,sizeof(struct sigaction));
    st.sa_handler = sig_block;
    st.sa_mask = set;
    sigaction(SIGUSR1, &st, NULL);
    sigaction(SIGUSR2, &st, NULL);


	// init processes 
	//
    for(int i=0; i<10; i++) {
        proc[i].p_id = i+1;
        proc[i].p_state = READY;
        q_add(context->qready, &proc[i]);
    } // for


    while(1) {
        print(context);
        step(context);
		sleep(1);
    } // while

    free(context);
    return 0;


}
