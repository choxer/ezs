#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void error() {


}

// add process to queue (last element)
void q_add(queue *q, process *proc) {
    printf("...adding Process to Queue\n");
    q_node *newNode;
    newNode = (q_node *)malloc(sizeof(q_node));
    if(!proc) error(); //return -1;
    newNode->p = proc;	
    newNode->next = NULL;

    if(!q) error(); //return -1;

    if(q->start == NULL) {
        q->start = newNode;
    }
    else if( q->start != NULL)
        q->end->next = newNode;
    q->end = newNode;

}

void q_print(queue *q) {
    printf("...printing Queue\n");
    q_node *tmp = q->start;
    int i = 0;
    if(!tmp)
        printf("ELEMENT QUEUE IS NULL\n");

    while(tmp) {
        i++;
        if(tmp->p) {
            printf("---%d.:\n", i);
            p_print(tmp->p);
        }
        tmp = tmp->next;
    }
    printf("...end of QUEUE\n\n");
}


process *q_remove(queue *q) {
    printf("...remove process from Queue\n");

    process *pPtr = q->start->p;

    q_node *qPtrTmp = q->start;

    q->start = q->start->next;

    free(qPtrTmp);

    return pPtr;


}
