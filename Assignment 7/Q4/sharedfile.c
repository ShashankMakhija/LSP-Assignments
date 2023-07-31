#include<stdio.h>
#include "sharedfile.h"
#include<dlfcn.h>
#include<stdlib.h>


int fact(int iNo)
{
    void *ptr = NULL;
    int (*fact_fptr)(int);

    ptr = dlopen("library2.so",RTLD_LAZY);
    if( ptr == NULL )
    {
        printf("unable to load library2\n");
        exit(1);
    }
    fact_fptr = dlsym(ptr,"factorial");

    return (fact_fptr(iNo));

}
