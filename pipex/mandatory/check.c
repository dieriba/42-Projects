#include "libft.h"

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

void    check_empty(int argc, char **argv)
{
    size_t  i;

    i = 0;
    while (++i < argc)
    {
        if (!argv[i][0])
            return (1);
    }
    return (0);
}
    info -> cmd = ft_strjoin("/", argv[1]);