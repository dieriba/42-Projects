#include "libft.h"

t_list	*ft_lstnew(void *content)
{
    t_list  *ptr;

    ptr = malloc(sizeof(t_list));
    if (!ptr)
        return (NULL);
    ptr -> next = NULL;
    ptr -> content = content;
    return (ptr);
}