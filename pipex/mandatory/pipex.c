#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int write_to_pipe(int fd[])
{
    close(fd[0]);
    int i = -1;
    int n = 20;
    int *new_arr = malloc(sizeof(int) * n);
    if (!new_arr)
        return (2);
    while (++i < n)
        new_arr[i] = i;
    if (write(fd[1], &n, sizeof(int)) < 0)
        return (3);
    if (write(fd[1], new_arr, (sizeof(int) * n)) < 0)
        return (4);
    
    close(fd[1]);
}

int read_from_pipe(int fd[])
{
    close(fd[1]);
    int i;

    i = -1;
    close(fd[1]);
    int n;
    int a[20];
    read(fd[0], &n, sizeof(int));
    read(fd[0], &a, sizeof(int) * 20);
    close(fd[0]);
    while (++i < n)
        printf("%d\n", a[i]);
    wait(NULL);
}

int main(int argc, char **argv, char **envp)
{
    int id;
    int fd[2];

    if (pipe(fd) < 0)
        return (1);
    id = fork();
    if (!id)
        write_to_pipe(fd);
    else
        read_from_pipe(fd);
}