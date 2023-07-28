// accept directory name from user
// copy first 10 bytes from all regular file and write it in new demo.txt

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    if( argc != 2 )
    {
        printf("invalid number of arguments \n");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    int fdDest = 0;

    char buffer[10] = {'\0'};
    int ret = 0;
    char path[50] = {'\0'};

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("unable to open dir\n");
        return -1;
    }

    sprintf(path , "%s/Demo.txt",argv[1]);
    fdDest = creat(path,0777 | O_APPEND );
    if( fdDest == -1 )
    {
        printf("unable to create new file .\n");
        return -1;
    }


    while( (entry = readdir(dp) ) != NULL )
    {
        if(entry -> d_type == 8 && (strcmp("Demo.txt", entry->d_name )) != 0) 
        {
            sprintf(path , "%s/%s" , argv[1] , entry -> d_name );
            fd = open(path,O_RDONLY);
            ret = read(fd , buffer , sizeof(buffer));
            printf(" -- %s --\n", entry -> d_name );

            write( fdDest , buffer , sizeof(buffer) );
            memset(buffer,0,sizeof(buffer));
        }
    }

    return 0;
}