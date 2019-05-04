#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define FAILURE -1
#define CHILD 0

void output(int var) {
    printf("(%u / %u)", getpid(), getppid());
    printf("var = %d\n", var);
}

int main() {
    int var = 0;
    int p = fork();

    if(p == FAILURE) exit(EXIT_FAILURE);
    output(++var);

    p = fork();


    if(p == FAILURE) exit(EXIT_FAILURE);
    output(++var);


    return EXIT_SUCCESS;

}
