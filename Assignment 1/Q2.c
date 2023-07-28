// Assignment 2 : Accept file name and mode from user and then open the in specifffied mode


#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(int argc , char *argv[] )
{
	int fd = 0;
	int mode = 0;

	if( argc != 3 )
	{
		printf("Invalid number of arguments!!!\n");
		return -1;
	}

	if( strcasecmp( argv[2] , "Read" ) == 0 )
	{
		mode = O_RDONLY;
	}
	else if( strcasecmp(argv[2]  , "Write" ) == 0 )
	{
		mode = O_WRONLY;
	}
	else if( strcasecmp(argv[2],"Read+Write") == 0 )
	{
		mode = O_RDWR;
	}
	else
	{
		printf("invalid mode entered ! \n");
		return -1;
	}

	fd = open(argv[1],mode);
	if( fd == -1 )
	{
		printf("unable to open file !");
		perror("open");
		return -1;
	}
	else
	{
		printf("File Successfully opend with fd %d with mode --> %s \n" , fd , argv[2]);
	}


	return 0;
}

