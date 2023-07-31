#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
	void *ptr = NULL;
	int (*addfptr)(int,int);
	int (*subfptr)(int,int);

	int iNo1 = 0 ;
	int iNo2 = 0;
	int iAns;

	ptr = dlopen("library.so",RTLD_LAZY);
	if( ptr == NULL )
	{
		printf("unable to load lib --> \n%s\n",dlerror());
		return -1;
	}

	addfptr = dlsym( ptr , "Addition" );
	subfptr = dlsym(ptr,"Substraction");
	if( addfptr == NULL || subfptr == NULL )
	{
		printf("unable to load address of function \n");
		return -1;
	}

	printf("Enter two numbers\n");
	scanf("%d%d",&iNo1 , &iNo2);

	iAns = addfptr(iNo1,iNo2);
	printf("Addition is --> %d \n",iAns);

	iAns = subfptr(iNo1 , iNo2);
	printf("Substraction is --> %d\n",iAns);

	
	return 0;
}