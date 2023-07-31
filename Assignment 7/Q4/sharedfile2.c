#include<stdio.h>
#include "sharedfile.h"
#include<dlfcn.h>
#include<stdlib.h>


int factorial(int n)
{
     int res = 1, i = 0;;
    for (i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;

}
