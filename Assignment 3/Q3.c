#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/stat.h>
#include<sys/types.h>

int main( int argc , char *argv[] )
{
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char oldname[50];
	char newname[50];

	if( argc != 3 )
	{
		printf("invalid number of arguments \n");
		return -1;
	}
	
	dp = opendir( argv[1] );
	if(dp == NULL)
	{
		printf("unable to open dir \n");
		return -1;
	}

	while( (entry = readdir(dp) ) != NULL )
	{
		sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		sprintf(newname,"%s/%s",argv[2],entry->d_name);

		rename(oldname,newname);
	}

	closedir(dp);
	return 0;

}