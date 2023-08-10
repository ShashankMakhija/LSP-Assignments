#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

int main()
{
    int ret = 0; int currPrio = 0;
    currPrio = getpriority(PRIO_PROCESS,0);
    ret = nice(currPrio-5);
    if( ret == -1 )
    {
        perror("nice->\n");
        return -1;
    }

    ret = getpriority(PRIO_PROCESS,0);
    printf("Priority of process is %d\n",ret);

    
    return 0;
}
