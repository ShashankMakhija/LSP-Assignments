#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/syscall.h>
#include<stdlib.h>
#include<stdio.h>

int main( int argc , char *argv[] )
{
	DIR *dp = NULL;
	struct dirent * entry = NULL;

	if( argc != 2 )
	{
		printf("invalid arguments \n" );
		return -1;
	}

	dp = opendir(argv[1]);

	if( dp == NULL )
	{
		printf("unable to open dir \n");
		return -1;
	}

	while( ( entry = readdir(dp) ) != NULL )
	{
		printf(" File Name :	%s | Type : %d \n" , entry -> d_name, entry -> d_type );
	}

	return 0;
}

