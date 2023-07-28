#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>

int main( int argc , char * argv[] )
{
	struct dirent *entry = NULL;
	DIR *dp = NULL;


	if( argc != 3 )
	{
		printf("invalid number of arguments \n");
		return -1;
	}

	dp = opendir(argv[1]);

	if( dp == NULL )
	{
		printf("Unable to open direc \n");
		return -1;
	}

	while( (entry =  readdir(dp)) != NULL )
	{
		if((strcmp( entry -> d_name , argv[2] )) == 0)
		{
			break;
		} 
	}
	if( entry == NULL )
	{
		printf("NO such file in the dir !\n");
	}
	else
	{
		printf("File exists in the dir ! \n");
	}



	return 0;
}
	