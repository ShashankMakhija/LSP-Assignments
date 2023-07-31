#include<stdio.h>
#include"sharedfile.h"

int Addition( int iNo1 , int iNo2 )
{
	int iAns = 0;
	iAns = iNo1 + iNo2;
	return iAns;
}

int Substraction( int iNo1 , int iNo2 )
{
	if( iNo1 > iNo2 )
	{
		return (iNo1 - iNo2); 
	}
	else if( iNo2 > iNo1 )
	{
		return (iNo2 - iNo1);
	}
	else
	{
		return 0;
	}
}
