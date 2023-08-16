#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

pthread_mutex_t mut;


// Thread 1 is to reverse the array 
void * ThreadProc1(void *ptr)
{	
	pthread_mutex_lock(&mut);



	int *arr = (int *)ptr;
	int size = arr[0];
	int temp = 0;
	
	int *arrback = &arr[size-1];
	arr++;
	

	for (int back = (size-1),i = 1; i != 6 ; arr++,arrback--,i++ )
	{
		temp = 0;

		temp = *arr;
		*arr = *arrback;
		*arrback = temp;


	}

	pthread_mutex_unlock(&mut);
	pthread_exit(NULL);
}

//is to display the array
void * ThreadProc2(void *ptr)
{	

	int *arr = (int *)ptr;
	int size = arr[0];
	int i = 0;
	
	for( int i = 1 ; i < size; i++ )
	{
		printf("Thread 2 --> %d\n",arr[i]);
	}

	pthread_exit(NULL);
}
int main()
{
	pthread_t TID1,TID2;
	int ret1 = 0,ret2 = 0;
	int *arr;
	int size = 10;

	int mut_ret = 0;

	mut_ret = pthread_mutex_init(&mut,NULL);
	if(mut_ret !=0)
	{
		printf("Unable to set mutex\n");
		return -1;
	
	}

	arr = (int*)malloc(size * sizeof(int));

	int i = 1;
	arr[0] = size;

	while( i < 10 )
	{
		arr[i] = i;
		i++;
	}

	
	ret1 = pthread_create(&TID1,                  
			     NULL,		     
			     ThreadProc1,     	    
			     (int *)arr); 		   
	
	if(ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;	
	}
	
	//printf("Thread1 is created with ID:%d\n",TID1);
	
	ret2 = pthread_create(&TID2,                   
			     NULL,		 
			     ThreadProc2,     	    
			     (int *)arr); 		    
	
	if(ret2 != 0)
	{
		printf("Unable to create thread\n");
		return -1;	
	}
	
	//printf("Thread2 is created with ID:%d\n",TID1);
	
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	sleep(3);
	printf("End of main Thread\n");	
	int itr = 1;
	while ( itr != size )
	{
		printf("-->%d\n",arr[itr]);
		itr++;
	}
	pthread_exit(NULL);
	return 0;
}