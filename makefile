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

processdemo: process.c

queuedemo: queue.c process.c

ctx_demo: queue.c process.c processmodel.c

all: $(binaries)

clean:
	$(RM)	*~ $(binaries) *.o
