#include<stdio.h>
#include"sharedfile.h"
#include <sys/stat.h>
#include<fcntl.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

bool fileIsEqual( char *f1, char *f2)
{
	int fd1 = 0 , fd2 = 0;
	
	char buffer1[BLOCKSIZE] = {'\0'};
	char buffer2[BLOCKSIZE] = {'\0'};
	int ret = 0;
	struct stat obj1;
	struct stat obj2;

	

	fd1 = open( f1 , O_RDONLY );
	fd2 = open( f2 , O_RDONLY );

	if( fd1 == -1 || fd2 == -1 )
	{
		printf("unable to open file \n");
		exit(1);
	}

	fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if( obj1.st_size != obj2.st_size )
    {
    	return false;
    }

	while( (ret = read(fd1,buffer1,BLOCKSIZE) ) != 0 )
	{
		ret = read(fd2,buffer2,BLOCKSIZE);
		if((memcmp(buffer1,buffer2,ret)) != 0)
		{
			break;
		}
	}

  	close(fd1);
    close(fd2);

	if(ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }	
}

