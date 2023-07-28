// Accept file name from user and read whole file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc , char *argv[])
{
	int fd = 0;
	char buffer[BLOCKSIZE] = {'\0'};
	int ret = 0;

	if( argc != 2 )
	{
		printf("invalid number of arguments \n");
		return -1;
	}


	fd = open ( argv[1] , O_RDONLY );

	if( fd == -1 )
	{
		printf("unable to open file \n");
		perror("open");
		return -1;
	}

	while( (ret=read(fd,buffer,BLOCKSIZE)) != 0 )
	{
		write(1,buffer,ret);
	}

	close(fd);


	return 0;
}
