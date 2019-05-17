#pragma once

#include "process.h"

typedef struct q_node {
    // möglichkeit ohne 'struct' keyword ?
    struct q_node *next;
    process *p;
} q_node;

typedef struct queue {
    q_node *start;
    q_node *end;
} queue;

// add process to queue (last element)
void q_add(queue *q, process *p);

void q_print(queue *q);

process *q_remove(queue *q);

///!!!!!!!!!!
void error();