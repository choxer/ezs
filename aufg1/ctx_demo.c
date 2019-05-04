#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "queue.h"
#include "process.h"
#include "processmodel.h"


int main() {
    pctx *context =  malloc(sizeof(pctx));
    if(!context) return 1;

    context->qready = malloc(sizeof(queue));
    context->qready->start = NULL;
    context->qready->end   = NULL;

     process *proc = malloc(10*sizeof(process));

	for(int i=0; i<10; i++){
		proc[i].p_id = i+1;
		proc[i].p_state = READY;
		q_add(context->qready, &proc[i]);
	} // for


	while(1) {
    		print(context);
   	 	step(context);
		sleep(1);
	} // while
	print(context);


    //free(qready);
    //free(proc);
    free(context);
    return 0;


}
