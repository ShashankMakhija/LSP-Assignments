#include <stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
    char *ptr = getenv("USER");
    if(ptr == NULL) 
    { 
        return -1;
    }
    printf("Username --> %s\n",p);

    ptr = getenv("HOME");
    if(ptr == NULL) 
    { 
        return -1;
    }

    printf("Home directory -->%s\n",p);

    return 0;
    
}