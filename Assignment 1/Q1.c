// Accept the ffile name form user and open that file


#include<stdio.h>
#include<fcntl.h>

int main( int argc , char *argv[] )
{
	int fd = 0;

	if(argc != 2)
	{
		printf(" Invalid number of arguments \n");
		return -1;
	}

	fd = open( argv[1] , O_RDONLY );

	if( fd == -1 )
	{
		printf("unable to open file\n");
		perror("open");
		return -1;
	}
	else
	{
		printf("file successfully opened with fd : %d \n",fd);
	}

	close(fd);


return 0;
}