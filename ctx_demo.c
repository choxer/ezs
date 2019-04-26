#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "process.h"
#include "processmodel.h"


int main() {

    pctx *context =  malloc(sizeof(pctx));
    if(!context) return 1;

    context->qready = malloc(sizeof(queue));
    process *proc = malloc(sizeof(process));
	
    proc->p_id = 1;

    q_add(context->qready, proc);
    print(context);
    step(context);

    //free(qready);
    //free(proc);
    free(context);
    return 0;


}
