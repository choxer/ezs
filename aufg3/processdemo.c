#include "process.h"
#include "queue.h"
#include <stdio.h>


int main() {

    process p = { .p_id = 1, .p_state = READY };
    process p2 = { .p_id = 2, .p_state = READY };

    printf("\n\n");

    p_print(&p);
    p_switch_state(&p);
    p_print(&p);
    p_switch_state(&p);
    p_print(&p);

    p_switch_state(&p2);
    p_print(&p2);

    printf("\n\n");

    return 0;
}
