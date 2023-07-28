#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc,  char *argv[])
{
    int fd = 0;
    char buffer[1]={'\0'};

    if (argc != 2) 
    {
        printf("Please enter the file name\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY | O_CREAT , 0777);

    if (fd == -1) 
    {
        perror("Unable to open file name\n");
        return -1;
    }

    lseek(fd, 1024, SEEK_END);
    write(fd, buffer, sizeof(buffer));

    close(fd);
    return 0;
}