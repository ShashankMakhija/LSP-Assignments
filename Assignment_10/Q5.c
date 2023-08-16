#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* ThreadProc(void* ptr)
{
    // using pthread_self() get current thread id
    printf("In function \nthread id = %d\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}
  
int main()
{
    pthread_t TID; int ret = 0;

    ret  = pthread_create(&TID, NULL, ThreadProc, NULL);
    if(ret != 0)
    {
        printf("Thread failed to create...\n");
    }
    
    printf("In main \nthread id = %d\n", thread); 

    pthread_join(TID, NULL); 

    return 0;
}