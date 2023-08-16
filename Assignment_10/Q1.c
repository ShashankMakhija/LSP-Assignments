#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc( void *ptr )
{
	printf("inside thread\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID;
	int ret = 0;

	ret = pthread_create(&TID,  
						NULL,
						ThreadProc,
						NULL);


	if( ret != 0 )
	{
		printf("unable to create thread\n");
		return -1;
	}

	printf("Thread is created with ID : %ld\n",TID);

	return 0;
}

