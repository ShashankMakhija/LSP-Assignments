#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include<string.h>

int main()
{
	
	int fd = 0;
	struct stat sobj;
	int ret = 0;


	DIR *dp = NULL;
	struct dirent *entry = NULL;
	char path[50] = {'\0'};
	char buffer[50] = {'\0'}; 

	fd = creat( "Demo.txt" , 0777 );
	if( fd == -1 )
	{
		printf("unable to create the file\n");
		return -1;
	}

	dp = opendir("/home/shashnk/Desktop");
	if( dp == NULL )
	{
		printf("unable to opendir \n");
		return -1;
	}

	write(fd,"Name of files in Desktop\n\n",26);
	while((entry = readdir(dp)) != NULL)
	{
		if( (entry->d_type) == 8 )
		{
			sprintf(buffer,"%s\n",entry->d_name);
			write(fd,buffer,strlen(buffer));
		}		
	}





	return 0;
}