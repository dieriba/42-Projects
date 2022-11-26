#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main (int argc, char **argv)
{
    int fd;
    char buffer[BUFFER_SIZE];
    char buffer1[BUFFER_SIZE];
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY);
    if (fd < 0)
        exit(1);
    while (1)
    {
        read(fd, buffer, BUFFER_SIZE);
        write(fd, buffer, BUFFER_SIZE);
        write(1, buffer, BUFFER_SIZE);
    }
    close(fd);
}