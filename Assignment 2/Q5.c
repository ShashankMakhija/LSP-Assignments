#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/syscall.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>

int main( int argc , char *argv[] )
{
	DIR *dp = NULL;
	struct dirent * entry = NULL;
	struct stat sobj;
	int max = 0;

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

	while( ( entry = readdir(dp) ) != NULL && (entry->d_type) == 8  )
	{
		stat((entry -> d_name) , &sobj );
		if( max < sobj.st_size )
		{
			max = sobj.st_size;
		}

	}
	printf("Max file size is : %d\n" , max );

	return 0;
}

