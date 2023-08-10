#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
	int ret = 0;
	int wstatus = 0;

	ret = fork();

	if ( ret == 0 )
	{
		execl("./process2",NULL,(char *)NULL);
	}
	else
	{
		printf("Process 1 is running..with PID %d\n",getpid());
		wait(&wstatus);
		printf("end of process 1\n");

	}

	return 0;
}