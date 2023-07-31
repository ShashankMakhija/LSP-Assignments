#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>
#include<stdlib.h>

int main()
{
	bool res = false;
	void *ptr = NULL;
	bool (*fptr)(char[],char[]);

	char f1[10] = {'\0'}, f2[10] = {'\0'};



	ptr = dlopen("library.so",RTLD_LAZY);
	if( ptr == NULL )
	{
		printf("unable to load lib --> \n%s\n",dlerror());
		return -1;
	}

	fptr = dlsym( ptr , "fileIsEqual" );
	if( fptr == NULL )
	{
		printf("unable to load address of function \n");
		return -1;
	}

	printf("Enter name of first file :\n");
	scanf("%s",f1);

	printf("enter name of second file :\n");
	scanf("%s",f2);

	res = fptr(f1,f2);

	if( res == true )
	{
		printf("both files are equal\n");
	}
	else
	{
		printf("nope!!! diffferent! \n");
	}

	return 0;

}
