WARNFLAGS = -W -Wall -Werror
OPTFLAGS = -O3
DEBUGFLAGS = -ggdb3 -DDEBUG
CFLAGS += $(WARNFLAGS)
binaries = processdemo queuedemo ctx_demo	

ifdef DEBUG
	CFLAGS += $(DEBUGFLAGS)
else
	CFLAGS += $(OPTFLAGS)
endif

all: $(binaries)

processdemo: process.c

queuedemo: queue.c process.c

ctx_demo: queue.c process.c processmodel.c


clean:
	$(RM)	*~ $(binaries) *.o
