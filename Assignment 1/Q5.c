// Accept file name and number of bytes from user and read that number of bytes from files

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
	int fd = 0;
	int bytes = 0;
	char *buffer = NULL;

	if( argc != 3 )
	{
		printf( "invalid input ! \n" );
		return -1;
	}	

	fd = open( argv[1] , O_RDONLY );
	if( fd == -1 )
	{
		printf( "file unable to open : " );
		perror("open");
		return -1;
	}

	bytes = atoi(argv[2]);
	buffer = (char *)malloc(bytes);

	int ret = read( fd , buffer , bytes );

	if( ret == 0 )
	{
		printf("unable to read \n");
		close(fd);
		return -1;
	}
	else
	{
		write(1 , buffer , ret );
	}

	close(fd);


	return 0;
}
