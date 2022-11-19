#include "pipex.h"





int    check(char *env, char *to_check, size_t size)
{
    size_t  i;

    i = -1;
    while ((to_check[++i] && env[++i]) && i < size && (to_check[i] == env[i]))
        ;
    if(env[i] == '=' && !to_check[i])
        return (1);
    return (0);
}

char    *find_path(char *envp[])
{
    size_t  i;

    if (!envp)
        return (NULL);
    i = -1;
    while (envp[++i])
    {
        if (envp[i][0] != 'P')
            continue;
        if (check(envp[i],"PATH", 4))
            return (envp[i]);
    }
    return (NULL);
}


int free_all(char **tab, char *tmp, int idx_err)
{
    size_t  i;

    i = -1;
    while (tab[++i])
    {
        if (i == idx_err)
            continue;
        free(tab[i]);
    }
    free(tmp);
    free(tab);
    
}
int main(int argc, char *argv[], char *envp[])
{
    // if (argc != 5)
    //     return (1);
    char    *path;
    char    **tab;
    char    *tmp;
    char    *cmd;

    cmd = ft_strjoin("/", argv[1]);
    if (!cmd)
        return (1);

    path = find_path(envp);
    if (!path)
        return (1);
    tab = ft_split(path + 5, ':');
    size_t i = -1;
    while (tab[++i])
    {
        tmp = tab[i];
        tab[i] = ft_strjoin(tab[i], cmd);
        if (!tab[i])
            return (free_all(tab, tmp, i));
        free(tmp);
    }
    i= -1;
    char **arg;
    while (tab[++i])
        execve(tab[i], arg, envp);
}
