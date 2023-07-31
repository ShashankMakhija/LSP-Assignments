#include<stdio.h>
#include "sharedfile.h"
#include<stdbool.h>

bool isPerfect( int iNo )
{
	int i = 0;
	int sum = 0;
	for(i=1; i<iNo; i++)
	{
		if(iNo%i == 0)
		{
			sum += i;
		}
	}

	if(sum == iNo)
	{
		return true;
	}
	else
	{
		return false;
	}
}