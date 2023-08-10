#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<fcntl.h>

int main(int argc, char* argv[])
{
	
	int ret = 0;
	int wstatus = 0;

	ret = fork();

	if( ret == 0 )
	{
		printf("child process pid %d\n",getpid());
		execl("./deamon",NULL,(char *)NULL);

	}
	else
	{
		printf("parent process pid %d\n",getpid());
	}
	return 0;
}
