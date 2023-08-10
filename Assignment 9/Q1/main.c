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
		execl("./process","NULL",(char *)NULL);
	}
	
	else
	{
		wait(&wstatus);
	}

	return 0;

	
}