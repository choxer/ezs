#pragma once

#include "process.h"
#include "queue.h"

typedef struct pctx {
    queue *qready;
	queue *qblocked;
    process *running;
} pctx;



// Kontext ausgeben
void print(pctx *ctx);



// mom. laufenden process (running) in warteschlange (qready) hinzufuegen
// erster prozess in warteschlange (qready) wird zum laufenden prozess (running)
void step(pctx *ctx);
