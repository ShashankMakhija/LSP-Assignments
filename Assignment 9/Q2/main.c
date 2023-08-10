#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>


int main()
{
	int ret1 = 0 , ret2 = 0 ;
    int wstatus = 0;

	ret1 = fork();
	if ( ret1 == 0 )
	{
		execl("./process1","NULL",(char *)NULL);
	}

	ret2 = fork();	
	if ( ret2 == 0 )
	{
		execl("./process2","NULL",(char *)NULL);
	}
	

	wait(&wstatus);

	return 0;

	
}