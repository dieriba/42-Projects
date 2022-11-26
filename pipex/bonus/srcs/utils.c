#include "pipex.h"

char    *create_file(t_data *info)
{
    char    *file;
    int     fd;
    // char    *LIMITER;

    // LIMITER = info -> LIMITER;
    fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC);
    if (fd < 0)
        print_err_and_exit("Error", info, 1);
    // while ()
    // {
    //     write()
    // }
    //ft_strcmp(get_next_line(fd), LIMITER);
    file = NULL;
    return (file); 
}