WARNFLAGS = -W -Wall -Werror
OPTFLAGS = -O3 -lreadline
DEBUGFLAGS = -ggdb3 -DDEBUG
CFLAGS += $(WARNFLAGS)
binaries = childprocess environ zombie

ifdef DEBUG
	CFLAGS += $(DEBUGFLAGS)
else
	CFLAGS += $(OPTFLAGS)
endif

all: $(binaries)

clean:
	$(RM)	*~ $(binaries) *.o
