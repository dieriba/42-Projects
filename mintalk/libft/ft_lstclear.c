#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *curr;
    t_list  *tmp;

    if (*(lst) == NULL || !(*del))
        return ;
    curr = *(lst);
    while (curr != NULL)
    {
        (*del)(curr -> content);
        tmp = curr -> next;
        free(curr);
        curr = tmp;
    }
    *(lst) = NULL;
}
