#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct cmd
{
    char    *cmd;
    char    *path;
    char    *args;
} cmd;


#endif