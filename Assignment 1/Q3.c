// 
#include<stdio.h>
#include<fcntl.h>
#include <errno.h>
#include<unistd.h>
#include<string.h>


int main( int argc , char * argv[] )
{
	int fd = 0; int mode = 0;


	if( argc != 3 )
	{
		printf("invalid number of arguments \n");
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

	if( (access(argv[1],mode) ) == F_OK )
	{
		printf(" file is accessable in the mode entered !\n ");
	}
	else
	{
		printf("file unable to open in that mode! \n");
	}


	

	return 0;
}