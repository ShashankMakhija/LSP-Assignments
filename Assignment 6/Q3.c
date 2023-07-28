#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main( int argc , char *argv[] )
{
	int fd = 0;
	if( argc != 3 )
	{
		printf("invalid number of arguments\n");
		return -1;
	}

	int dp = 0;
	char path[255] = {'\0'};
	

	dp = mkdir(argv[1],0777);

	sprintf(path , "%s/%s",argv[1],argv[2]);

	fd = creat(path , 0777);

	close(fd);
	close(dp);



	return 0;
}