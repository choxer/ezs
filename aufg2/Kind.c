#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define CHAILD 0

void handler1()
{
	char* owner=getlogin();
	printf("Goodbey %s\n", owner);
}

int main()
{

	int p=fork();
	size_t pid, ppid;
	


	if (p < CHAILD)
	{
		exit(EXIT_FAILURE);
	}
	else if (p>CHAILD) //Eltern Prozess
	{
		printf("PID von Kind %u\n", pid);
		sleep(1);
	}
	else if (p==CHAILD) //Kind Prozess
	{
		printf("PID von Kind %u\n", pid);
		printf("PID von Vater %u\n", ppid);
		sleep(1);
		printf("INIT Vater %u\n", ppid);
		sleep(1);
		atexit(handler1);	
	}

	exit(EXIT_SUCCESS);
}
