
#include <stdio.h>
#include "limits.h"
#include "ft_printf.h"
int main()
{
    void *p;
    // ft_printf
    // ("\nPrintf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n, Printf : %i, ft_printf: %i\n", printf("%i", 2546), ft_printf("%i", 2546), printf("%i", -15000), ft_printf("%i", -15000), printf("%s", "BONJOUR"), ft_printf("%s", "BONJOUR"), printf("%X", 2147483647), ft_printf("%X", 2147483647), printf("%X", -2147483647), ft_printf("%X", -2147483647), printf("%p", p), ft_printf("%p", p), printf("%c", 'a'), ft_printf("%c", 'a'), printf("%u", 4294967295), ft_printf("%u", 4294967295), printf("%c", '%'), ft_printf("%c", '%'));
    //  ft_printf("\nft_printf: %x, printf: %x", 16, 16 ); 
    // ft_printf("%i", ft_printf("%s", NULL));
    // ft_printf("My Ft : %i", ft_printf("printf : %\n"));
    // ft_printf("Printf Value : %i", ft_printf("Printf : %\n"));
    // ft_printf("%i", 250);
    // printf("%0", "5610");
    printf(" %w ", -15);
    return 0;
}