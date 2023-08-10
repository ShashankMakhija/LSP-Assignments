#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("process 2 is running... with PID %d | PPID --> %d\n",getpid(),getppid());
	return 0;
}