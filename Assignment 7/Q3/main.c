#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{

	void *ptr1 = NULL;
	void *ptr2 = NULL;
	int iNo = 0;

	bool res1 = false;
	bool res2 = false;

	bool (*isPrime_fptr)(int);
	bool (*isPerfect_fptr)(int);


	ptr1 = dlopen("library1.so",RTLD_LAZY);
	ptr2 = dlopen("library2.so",RTLD_LAZY);
	if( ptr1 == NULL || ptr2 == NULL  )
	{
		printf("unable to load lib --> \n%s\n",dlerror());
		return -1;
	}

	isPrime_fptr = dlsym(ptr1,"isPrime") ;
	isPerfect_fptr = dlsym(ptr2,"isPerfect");

	printf("Enter number to check \n");
	scanf("%d",&iNo);


	res1 = isPrime_fptr(iNo);
	if( res1 == true )
	{
		printf("number is prime\n");
	}
	else
	{
		printf("Not Prime!\n");
	}

	res2 = isPerfect_fptr(iNo);
	if( res2 == true )
	{
		printf("Number is Perfect\n");
	}
	else
	{
		printf("Number NOT Perfect\n");
	}

	return 0;
}