#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc1( void *ptr )
{
	int itr = 1;
	while( itr != 501 )
	{
		printf( "Thread1-->%d\n",itr );
		itr++;
	}
	  pthread_exit(NULL);
}

void *ThreadProc2( void *ptr )
{
	int itr = 500;
	while( itr != 0 )
	{
		printf( "Thread2-->%d\n",itr );
		itr--;
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t TID1,TID2;
	int ret1 = 0 , ret2 = 0;

	ret1 = pthread_create(&TID1,  
						NULL,
						ThreadProc1,
						NULL);
	if( ret1 != 0 )
	{
		printf("unable to create thread\n");
		return -1;
	}

	ret2 = pthread_create(&TID2,  
						NULL,
						ThreadProc2,
						NULL);
	if( ret2 != 0 )
	{
		printf("unable to create thread\n");
		return -1;
	}

	pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);



	return 0;
}


