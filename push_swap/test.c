#include <stdio.h>

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int    check_args(int argc, char **argv)
{
    int  i;
    int  j;

    j = -1;
    i = 0;
    while(++i < argc)
    {
        if (argv[i][0] == '-')
                j++;
            printf("value of j : %i", j);
        while (argv[i][++j])
        {   
            printf("value of j : %i", j);
            if (!ft_isdigit(argv[i][j]))
            {
                printf("Only digits are accepted as arguments !\n");
                return (0);
            }
        }
        j = -1;
    }
    return (1);
}


int main (int argc, char **argv)
{
    if (!check_args(argc, argv))
        printf("Wrong type of args");
}