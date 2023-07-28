#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;    
    
    fd = open(argv[1], O_RDONLY);

    if (argc != 3) {
        printf("Please specify filename and bytes\n");
        return 0;
    }
    
    if (fd == -1) {
        printf("Unable to open file\n");
        return -1;
    } else {
        printf("File opened successfully\n");
    }
    
    ret = truncate(argv[1], atoi(argv[2]));
    
    if (ret == -1) {
        printf("Unable to truncate data");
    } else {
        printf("Data truncated successfully");
    }
    
    close(fd);
    
    return 0;
}