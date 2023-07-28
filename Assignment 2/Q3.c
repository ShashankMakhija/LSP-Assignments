//

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include <sys/syscall.h>

int main( int argc , char * argv[] )
{
	if( argc != 2 )
	{
		printf("invalid number of arguments \n");
		return -1;
	}

	DIR *dir = NULL;
	struct dirent *entry = NULL;
 
	dir = opendir(argv[1]);
	if( dir == NULL )
	{
		printf(" faild to open dir : \n");
		return -1;
	}

	entry = readdir(dir);
	if( entry == NULL )
	{
		printf("unable to read dir : \n");
		return -1;
	}

	while(entry != NULL)
	{
		printf("  %s   \t \n" , entry -> d_name );
		entry = readdir(dir);
	}

	//close(dir);




	return 0;
}