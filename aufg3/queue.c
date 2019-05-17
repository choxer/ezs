#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


// add process to queue (last element)
void q_add(queue *q, process *proc) {
    if(!proc) return;
    if(!q)    return;
 
    q_node *newNode = (q_node *)malloc(sizeof(q_node));
    newNode->p = proc;	
    newNode->next = NULL;


    if(q->start == NULL) {
        q->start = newNode;
    }
    else if( q->start != NULL)
        q->end->next = newNode;
    q->end = newNode;

}

void q_print(queue *q) {
	if(!q)
		return;
    printf("...printing Queue\n");
	q_node *tmp = q->start;
    if(!tmp) {
        printf("QUEUE is empty\n");
        //return;
    }	

    int i = 0;
    while(tmp) {
        i++;
        if(tmp->p) {
            printf("---%d.:\n", i);
            p_print(tmp->p);
        }
        tmp = tmp->next;
    }
    printf("__end of QUEUE\n\n");
}


process *q_remove(queue *q) {
#ifdef DEBUG
    printf("...remove process from Queue\n");
#endif
    process *pPtr = q->start->p;

    q_node *qPtrTmp = q->start;

    q->start = q->start->next;

    free(qPtrTmp);
    return pPtr;


}
