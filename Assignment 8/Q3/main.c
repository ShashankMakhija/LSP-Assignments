#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


int main()
{
	int ret1 = 0 , ret2 = 0 , ret3 = 0;
	int wstatus = 0;

	ret1 = fork();
	

	if ( ret1 == 0 )
	{
		execl("./process1",NULL,(char *)NULL);
	}
	wait(&wstatus);

	ret2 = fork();	
	if ( ret2 == 0 )
	{
		execl("./process2",NULL,(char *)NULL);
	}
	wait(&wstatus);

	ret3 = fork();
	if ( ret3 == 0 )
	{
		execl("./process3",NULL,(char *)NULL);
	}

	
	wait(&wstatus);

	return 0;

	
}