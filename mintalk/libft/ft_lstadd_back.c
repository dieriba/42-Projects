#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
    if (*(alst) == NULL)
        *(alst) = new;
    else
        {
            t_list  *lst;

            lst = ft_lstlast(*(alst));
            lst -> next = new;           
        }
}