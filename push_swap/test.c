#include "libft/libft.h"
#include <stdio.h>

void    copy_over(char **tabs, char *num)
{
    static int i;
    tabs[i] = num;
}

char    **tabs(int argc, char **argv)
{
    size_t  i;
    char    ***tab;
    int     tablen;
    char    *tabs;
    int     j;

    j = -1;
    i = -1;
    tab = malloc(sizeof(char**) * argc);
    if (!tab)
        return (NULL);
    while (++i < argc)
    {
        tab[i] = ft_split(argv[i + 1], ' ');
        // if (!tab[i])
        //     return (free_splited(tabs));
    }
    tab[argc - 1] = 0;
    i = -1;
    while (tab[++i])
    {
        tablen += ft_tab_len(tab[i]);
        printf("tablen[%li] : %d\n", i , tablen);
    }
    tabs = ft_calloc(sizeof(char *), tablen);
    if (!tabs)
        return (NULL);
    i = -1;
    while (tab[++i])
    {
        while (tab[i][++j])
        {
            printf("%s ", tab[i][j]);
        }
        j = -1;
        printf("\n");
    }
}


int main (int argc, char **argv)
{
    tabs(argc, argv);
}