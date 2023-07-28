// print all the information about that file

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main( int argc , char * argv[] )
{
	int fd = 0;
	struct stat sobj;

	if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if( fd == -1 )
    {
    	printf("file unable to open\n");
    	return -1;
    }


    fstat( fd , &sobj );
    printf("File size is 	: %d\n",sobj.st_size);
    printf(" ID of device containing file :%ld\n",sobj.st_dev);
    printf("inode number	:%ld\n",sobj.st_ino);
    printf("protection 	:%ld\n",sobj.st_mode);
    printf("user ID of owner: %ld\n",sobj.st_uid);
   	printf("blocksize for file system I/O : %ld \n",sobj.st_blksize);   	
    printf("number of blocks allocated : %ld\n",sobj.st_blocks);

    close(fd);

	return 0;
}
