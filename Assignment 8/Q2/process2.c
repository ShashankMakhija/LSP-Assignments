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
		execl("./process3",NULL,NULL);
	}
	else
	{
		printf("Process 2 is running..with PID --> %d | PPID --> %d\n",getpid(),getppid());
		wait(&wstatus);
		printf("end of process 2\n");

	}

	return 0;
}