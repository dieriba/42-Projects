#include "libft.h"

int     ft_tablen(char const *s, char c)
{
        size_t  i;
        size_t  len;

        len = 0;
        i = 0;
        while (s[i])
        {
            while (s[i] && s[i] == c)
                i++;
            if (s[i])
                len++;
            while (s[i] && s[i] != c)
                i++;
        }
        return (len);
}

void    fill_tab(char **tab, char const *s, char c, int len)
{
        int i;
        int j;
        int k;
        int m;

        i = 0;
        j = 0;
        while (i < len)
        {
            while (s[j] && s[j] == c)
                j++;
            k = j;
            while (s[k] && s[k] != c)
                k++;
            tab[i] = malloc(sizeof(char) * (k - j + 1));
            if (!tab[i])
                return ;
            m = 0;
            while (j < k)
                tab[i][m++] = s[j++];
            tab[i][m] = 0;
            i++;
        }
        tab[i] = 0;
}

char **ft_split(char const *s, char c)
{
    char    **tab;
    int     len;

    len = ft_tablen(s, c);
    tab = malloc(sizeof(char *) * (len + 1));
    if (!tab)
        return (NULL);
    fill_tab(tab, s, c, len);
    return (tab);
}
