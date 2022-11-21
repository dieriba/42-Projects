#include "libft.h"

void    free_tab(char **tab)
{
    size_t  i;

    if (!tab)
        return ;
    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);  
}