#include<fcntl.h>
#include<stdio.h>
#include<dirent.h>
#include <sys/stat.h>


int main( int argc , char * argv[] )
{	
	int dir = 0;

	if( argc != 2 )
	{
		printf("invalid number of arguments \n");
		return -1;
	}

	dir = mkdir( argv[1] , 0777 );

	if( dir == 0 )
	{
		printf("Dir successfully created \n");
	}
	else
	{
		printf("Dir unable to create \n");
		return -1;
	}



	return 0;
}