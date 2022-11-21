#include "pipex.h"

void    init_files(t_data *info, char *files_one, char *files_two)
{
    char    **files;
    size_t  i;

    i = -1;
    files = malloc(sizeof(char*) * 3);
    if (!files)
        print_err_and_exit("Failled to allocate memory", info);
    files[0] = ft_strdup(files_one);
    files[1] = ft_strdup(files_two);
    info -> files = files;
}

void    fill_struct (t_cmd *cmds, char *argv)
{
    char    **tab;
    int     len;
    int  i;

    i = 0;
    tab = ft_split(argv, ' ');
    if (!tab)
        print_err_and_exit("Failled to allocate memory", cmds -> info);
    cmds -> cmd = tab[0];
    len = ft_tab_len(tab);
    cmds -> args = NULL;
    cmds -> paths = NULL;
    if (len == 1)
    {   
         free(tab[1]); 
         free(tab);
    }
    cmds -> args = malloc((sizeof(char *) * len + 1));
    if (!cmds -> args)
        print_err_and_exit("Failled to allocate memory", cmds -> info);
    while (++i <= len)
        cmds -> args[i - 1] = tab[i];
    free(tab);
}



void    set_cmds_data(t_data *info, t_cmd **cmds, char *path)
{
    size_t  i;

    i = -1;
    while (++i < 2)
    {
        cmds[i] -> info = info;
        cmds[i] -> path = path;
    }
    
}

void    init_cmd(t_data* data, char **argv, char *envp[])
{
    t_cmd   **cmds;
    size_t  i;

    i = -1;
    cmds = ft_calloc(sizeof(t_cmd *), 3);
    if (!cmds)
    {
        perror("Failled To Allocate Memory");
        exit(EXIT_FAILURE);
    }
    while (++i < 2)
    {
        cmds[i] = malloc(sizeof(t_cmd));
        if (!cmds[i])
            print_err_and_exit("Failled to allocate memory", data);
    }
    data -> cmd_data = cmds;
    init_files(data, argv[1], argv[4]);
    set_cmds_data(data, data -> cmd_data, find_path(envp));
    fill_struct(cmds[0], argv[2]);
    fill_struct(cmds[1], argv[3]);
    set_path_type(cmds);
    set_path(cmds);
}