// Accept name and write string in that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main( int argc , char * argv[] )
{
	int fd = 0;
	char *buffer = NULL;

	if( argc != 2 )
	{
		printf("invalid number of arguments!\n");
		return -1;
	}

	fd = creat( argv[1] , 0777 );

	if( fd == -1 )
	{
		printf("failed to create file!\n");
		perror("creat");
		return -1;
	}

	printf("Enter data to store in file: \n");
	scanf("%ms" , &buffer);

	int size = 0;
	char *temp = buffer;
	while(*temp != '\0')
	{
		size++;
		temp++;
	}
	

	printf("%d \n",size);
	printf("%d \n",tp);

	write( fd , buffer , size );

	close(fd);

	return 0;
}
