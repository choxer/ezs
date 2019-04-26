#include "process.h"
#include <stdio.h>
#include <stdlib.h>


void p_switch_state(process *p) {

    printf("...switching state of process (ID): %d\n", p->p_id);

    if (p->p_state == READY)
        p->p_state = RUNNING;
    else if (p->p_state == RUNNING)
        p->p_state = READY;
    else {
        // FEHLERMELDUNG AUSARBETIEN
        fprintf(stderr, "FEHLERMELDUNG");
        exit(1);
    }
}


void p_print(process *p) {

    printf("Prozess-ID: %d\n", p->p_id);

    if (p->p_state == READY)
        printf("Prozess-Status: 'READY'\n");
    else if (p->p_state == RUNNING)
        printf("Prozess-Status: 'RUNNING'\n");
    else {
        // FEHLERMELDUNG AUSARBETIEN
        fprintf(stderr, "ERROR: p_state\n");
        //exit(1);
        return;
    }
}
