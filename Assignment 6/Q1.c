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

#define BLOCKSIZE 1024

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

	
	int fdDest = 0;
	int ret = 0;


	fdDest = open("Finfo.txt", O_RDONLY);
	struct Finfo fobj;
	
	while(ret = read(fdDest , &fobj , sizeof(fobj)) != 0 )
	{
		if( fobj.size > 10 )
		{
			printf("File name --> %s  size --> %d \n",fobj.Fname , fobj.size);
		}
		lseek(fdDest, fobj.size, SEEK_CUR);
	}

	return 0;
}