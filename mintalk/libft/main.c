#include "libft.h"
#include <stdio.h>

int main (int argc, char **argv)
{
    char big[] = "Bonjour c'est moie dierba";
    char little[] = "Bonjour";
    printf("%s\n", ft_strnstr(big, little, 0));
}