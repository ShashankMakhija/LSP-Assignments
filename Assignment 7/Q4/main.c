#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int);
    int iNo = 0 ;


    ptr = dlopen("library1.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary %s\n",dlerror());
        return -1;
    }

    fptr = dlsym(ptr,"fact");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    printf("enter number : \n");
    scanf("%d",&iNo);
    printf( "factorial of number is : %d\n",fptr(iNo) );

    return 0;
}


