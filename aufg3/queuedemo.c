#include "process.h"
#include "queue.h"

#include <stdio.h>
#include <malloc.h>

int main() {


    //printf("------------------------------------------------\n");

    // new Process(es)
    // mit NULL initialisieren
    process P1 = { .p_id = 666, .p_state = READY };
    process P2 = { .p_id = 999, .p_state = READY };
    process P3 = { .p_id = 111, .p_state = READY };

    // new queue(s)
    // mit NULL initialisieren
    queue Q1 = { .start = NULL, .end = NULL };
    //queue Q2 = { .start = NULL, .end = NULL };


    ////////////////////////////////////////////////

    //printf("\n--Prozess P1 mit 'p_print' ausgeben:\n");
    //p_print(&P1);

    //printf("\n--Warteschlange Q1 mit 'q_print' ausgeben:\n");
    //q_print(ptrQ1);

    //printf("\n--Warteschlange Q1 mit Prozess P1 auffüllen..\n");
    //q_add(&Q1, &P1);


    //printf("\n--Warteschlange Q1:\n  P1:\n");
    //p_print();


    //printf("\n--Warteschlange Q1 mit 'q_print' ausgeben:\n");
    //q_print(ptrQ1);

    //printf("\n--Warteschlange Q2 mit Prozess P2 auffüllen..\n");
    //q_add(&Q2, &P2);

    //printf("\n--Warteschlange Q1 mit 'q_print' ausgeben:\n");
    //q_print(ptrQ1);

    q_add(&Q1, &P1);
    q_add(&Q1, &P2);
    q_add(&Q1, &P3);

    q_print(&Q1);

    process *returnProc = q_remove(&Q1);
    printf("..geloeschter Prozess:\n");
    p_print(returnProc);

    q_print(&Q1);


    //// FREEEEEEEEEEEEEEEEEE

    //q_print(&Q1);



    //printf("\n-------------------------------------------------\n\n");

    return 0;
}
