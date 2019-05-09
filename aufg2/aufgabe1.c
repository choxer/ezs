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
	
	if (p>CHAILD) //Eltern Prozess
	{
		
		printf("Vater   %u, %u\n", getppid(), getpid() );
		atexit(handler1);
		exit(0);
		
	}
	else if (p==CHAILD) //Kind Prozess
	{
		printf("Kind   %u, %u\n", getppid(), getpid() );
		
	}
	while(1){}
	return 0;
}