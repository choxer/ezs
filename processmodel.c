#include <stdio.h>

#include "processmodel.h"
#include "process.h"
#include "queue.h"

void print(pctx *ctx) {
    printf("...printing context\n");
    if(ctx->qready) {
        printf("-- Warteschlange QREADY:\n");
        q_print(ctx->qready);
        printf("-- Prozess RUNNING:\n");
        if(ctx->running)
            p_print(ctx->running);
        else
            printf("ELEMENT RUNNING IS NULL\n");
    }
    else
        printf("Ungueltiger CONTEXT; ELEMENT QREADY IS NULL\n");

    printf("...end of context\n\n");
}


void step(pctx *ctx) {
    	if(ctx->running)
		p_switch_state(ctx->running);
	printf("TEST\n");
	q_add(ctx->qready, ctx->running);
    	
	// DATENKAPSELUNG BEACHTEN ; INTERNA VON QUEUE SIND INTERN!;
	ctx->running = q_remove(ctx->qready);
    	p_switch_state(ctx->running);
    	//q_print(ctx->qready);
}
