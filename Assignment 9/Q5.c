#include <sched.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0; int ret2=0;

    setpriority(PRIO_PROCESS,0,-5);
    if( ret == -1 )
    {
        perror("ret->\n");
        return -1;
    }

    ret = getpriority(PRIO_PROCESS,0);
    printf("Priority of process is %d\n",ret);

    ret2 = sched_yield();
    if( ret2 == -1 )
    {
    	perror("yield-->");
    	return -1;
    }

    
    return 0;
}