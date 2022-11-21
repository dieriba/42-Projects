#include "libft.h"

int ft_tab_len(char **tab)
{
    int  i;

    if (!tab)
        return(0);
    i = -1;
    while(tab[++i])
        ;
    return (i);
}