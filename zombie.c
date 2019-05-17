#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

// ps -eo pid,üüid,stat,cmd
// waitpid();:w

#define CHILD 0
#define FAILURE -1

int main(int argc, char *argv[])
{
    // fehlerabfrage
    if(argc == 1) {
        fprintf(stderr, "usage: ./zombie <k>\n(k=number of zombieprocesses)\n");
        return EXIT_FAILURE;
    }
    pid_t pid = 0;
    int num = atoi(argv[1]);

    if(num == -1) {
        // many as possible
        while(1) {
            pid = fork ();
            if(pid == CHILD) {
                printf("pid: %d / ppid: %d\n", getpid(), getppid());
            	sleep(5);
                printf("pid: %d / ppid: %d\n", getpid(), getppid());
			}
            else if(pid > CHILD)
                kill(getpid(), SIGKILL);
            else return EXIT_FAILURE;
        }
    }
    else {
        for(int i=0; i<num; i++) {
            pid = fork ();
            if(pid == CHILD) {
                printf("pid: %d / ppid: %d\n", getpid(), getppid());
            	sleep(5);
                printf("pid: %d / ppid: %d\n", getpid(), getppid());
			}
            else if(pid > CHILD)
                kill(getpid(), SIGKILL);
            else return EXIT_FAILURE;
        } //for
        sleep(5);
    }
    //printf("%d\n", pid);
    sleep(10);
    return EXIT_SUCCESS;
}
