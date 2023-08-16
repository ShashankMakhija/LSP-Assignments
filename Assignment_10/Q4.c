#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void* ThreadProc(void* ptr)
{
    int iNo = 7;

    pthread_exit(No);
}


int main()
{

    pthread_t TID;
    int ret = 0;
    int res = 0;

    ret = pthread_create(&TID,
                        NULL,
                        ThreadProc,
                        NULL);
    
    if(ret != 0)
    {
        printf("Thread failed to create...\n");
    }

    printf("Thread1 created Successfully with id : %ld\n",TID);

    pthread_join(TID,&res);

    printf("Return from thread proc function  is : %d\n",res);

    return 0;
}