#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>

int main()
{
	int ret = 0;
	int wstatus = 0;

	ret = fork();

	if( ret == 0 )
	{
		printf("child process is running \n");
		for(int i = 0 ; i < 0xFFFFFFFF; i++);
		printf("child end..\n");
	}
	else
	{
		printf("Parent process is running\n");
		wait(&wstatus);
		printf("parent process end..\n");
	}

	return 0;
}