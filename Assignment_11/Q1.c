#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void* ThreadProc1(void* ptr)
{
    printf("Thread 1 is created \n");
}

void* ThreadProc2(void* ptr)
{
    printf("Thread 2 is created \n");
}

void* ThreadProc3(void* ptr)
{
    printf("Thread 3 is created \n");
}

void* ThreadProc4(void* ptr)
{
    printf("Thread 4 is created \n");
}


int main()
{

    pthread_t TID1,TID2,TID3,TID4;
    int ret1 = 0,ret2 = 0,ret3 = 0,ret4 = 0;

    printf("Thread id of Main thread is : %ld\n",pthread_self());

    ret1 = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(ret1!=0)
    {
        printf("Thread is not created...");
    }

    ret2=pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(ret2!=0)
    {
        printf("Thread is not created...");
    }

    ret3=pthread_create(&TID3,NULL,ThreadProc3,NULL);
    if(ret3!=0)
    {
        printf("Thread is not created...");
    }

    ret4=pthread_create(&TID4,NULL,ThreadProc4,NULL);
    if(ret1!=0)
    {
        printf("Thread is not created...");
    }
    
    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);

    printf("End of main thread..");
    return 0;
}