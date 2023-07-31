#include<stdio.h>
#include "sharedfile.h"
#include<stdbool.h>

bool isPrime( int iNo )
{
	int temp = 0;
	for (int i = 2; i <= iNo / 2; i++)
    {
        if(iNo % i == 0)
        {
            temp++;
            break;
        }    
    } 

    if( temp == 0 && iNo != 1)
    {
    	return true;
    }

    else
    {
    	return false;
    }
}
