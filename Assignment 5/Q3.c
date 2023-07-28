// info about all files in dir  --> into file and then read that info 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/syscall.h>

#pragma pack(1)
struct Finfo
{
	char Fname[20];
	int size;
};

int main( int argc , char *argv[] )
{
	if( argc != 2)
	{
		printf("invalid number of arguments\n");
		return -1;
	}

	DIR *dp = NULL;
	struct dirent *entry = NULL;
	int fdDest = 0;

	dp = opendir(argv[1]);
	if( dp == NULL )
	{
		printf("unable to open dir\n");
		return -1;
	}

	fdDest = creat("Finfo.txt",0777);
	struct Finfo fobj;
	struct stat sobj;
	while( ( entry = readdir(dp) ) != NULL && (entry->d_type) == 8  )
	{
		stat((entry -> d_name) , &sobj );
		fobj.size = sobj.st_size;
		strcpy( fobj.Fname , entry -> d_name );

		write(fdDest , &fobj ,sizeof(sobj) );
	}

	return 0;
}