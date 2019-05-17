#include <stdio.h>

#include "processmodel.h"
#include "process.h"
#include "queue.h"

void print(pctx *ctx) {
    printf("...printing context\n");
    if(ctx->qready == NULL) {
        return;
    }

    printf("-- Warteschlange QREADY:\n");
    q_print(ctx->qready);
    printf("-- Prozess RUNNING:\n");
    if(ctx->running)
        p_print(ctx->running);
    else
        printf("ELEMENT RUNNING IS NULL\n");

    printf("-- Warteschlange QBLOCKED:\n");
    q_print(ctx->qblocked);
    printf("___end of context\n\n");
}


void step(pctx *ctx) {
    if(ctx->running) {
        	p_switch_state(ctx->running);
        	q_add(ctx->qready, ctx->running);
}    
		ctx->running = q_remove(ctx->qready);
			if(ctx->running)
				p_switch_state(ctx->running);
	
	
}
