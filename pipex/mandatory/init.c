#include "pipex.h"

void    init_files(t_data *info, char *files_one, char *files_two)
{
    char    **files;

    if (!files_one[0] || !files_two[0])
        //function exit prog
    files = info -> files;
    files = malloc(sizeof(char*) * 2);
    if (!files)
        //function to exit prog
    files[0] = files_one;
    files[1] = files_two;
}
int    fill_struct (t_cmd *cmds, char *argv)
{
    char    **tab;
    int     len;
    size_t  i;

    i = 0;
    tab = ft_split(argv, ' ');
    if (!tab)
        //exit function
    cmds -> cmd = tab[0];
    len = ft_tab_len(tab);
    if (len == 1)
    {   
        free(tab[1]); 
        free(tab);
        return (0);
    }
    cmds -> args = malloc((sizeof(char *) * len + 1));
    if (!cmds -> args)
        return (free_tab(tab));
    while (++i <= len)
        cmds -> args[i - 1] = tab[i];
    free(tab);
    return (0);
}

void    set_path_type(t_cmd **cmd_data)
{
    size_t  i;

    i = -1;
    while (cmd_data[++i])
    {
        /* code */
    }
        
}

void    init_cmd(t_data* data, char **argv, char **envp)
{
    t_cmd   **cmds;
    char    **tab;
    char    *tmp;

    cmds = malloc(sizeof(t_cmd) * 3);
    if (!cmds)
        //function to exit;
    cmds[2] = 0;
    fill_struct(cmds[0], argv[1]);
    fill_struct(cmds[1], argv[2]);
    set_pat_type(cmds);
    data -> cmd_data = cmds;
}
// t_cmd   *cmds;
//     char    *path;
//     size_t  i;

    // i = -1;
    // cmds = cmd_data;
    // path = find_path(envp);
    // if (!path)
    //     //create custom fuction for free and return erorr
    // cmds -> paths = ft_split(path + 5, ':');
    // if (!cmds -> paths)
    //     //exit function and
    // while (tab[++i])
    // {
    //     tmp = tab[i];
    //     tab[i] = ft_strjoin(tab[i], cmd);
    //     if (!tab[i])
    //     {
    //        free_all(tab, tmp, i);
    //        break;
    //     }
    //     free(tmp);
    // }