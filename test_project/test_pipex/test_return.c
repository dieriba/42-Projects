#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

#include <fcntl.h>

int main ()
{
    int fd;

    fd = open("test", O_RDWR | O_CREAT | O_APPEND);
    write(fd,"bonjour", 7);
}