#pragma once
#include "stdint.h"

typedef enum state {
    READY,
    RUNNING
} state;

typedef struct process {
    uint32_t p_id;
    state p_state;
} process;

// change process state (RUNNING/READY)
void p_switch_state(process *p);

// human readable
void p_print(process *p);