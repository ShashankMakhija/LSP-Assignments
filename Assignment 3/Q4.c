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
	int fd = 0;
	char path[50] = {'\0'};

	struct stat obj;


	if( argc != 2 )
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
		
		sprintf(path,"%s/%s", argv[1], (entry -> d_name) );

		stat( path , &obj );
		if( obj.st_size == 0 )
		{
			sprintf(path,"%s/%s", argv[1], (entry -> d_name) );
			printf("%s --> Deleted\n",path); 
			remove(path);
		}

	}

	closedir(dp);



	return 0;
}
	
