#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHILD 0
void goodbye(void) {
    printf("Goodbye %s\n", getlogin());
}

int main() {
    pid_t pid;

    // create childprocess
    //
    pid = fork();
    if( pid == CHILD) {
        printf("CHILD: pid: %d / ppid: %d\n", getpid(), getppid());
		sleep(5);
        printf("\n..wait for it..\n");
        printf("CHILD: pid: %d / ppid: %d\n", getpid(), getppid());
    }
    // kill parentprocess
    //
    else if( pid > CHILD) {
        printf("PARENT: pid: %d / ppid: %d\n", getpid(), getppid());
        // exithandler "Goodbye"
        atexit(goodbye);
        //kill(getpid(), SIGKILL);
    }
    else return EXIT_FAILURE;
    // watch with ps -eo (..)
    // better: show ppid from childprocess
    return EXIT_SUCCESS;
}
