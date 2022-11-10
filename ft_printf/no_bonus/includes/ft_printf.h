#ifndef LIBPRINTF_H
#define LIBPRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#define BASE_FORMAT "cspdiuxX%%-0.# +"

int ft_putchar(char c);
int ft_putnbr_uns(unsigned int nbr, int *count);
int ft_putnbr_base_hex(unsigned int nbr, int transform, int *count);
int ft_putnbr(int n, int *count);
int ft_putstr_fd(char *s, int fd);
int valid_format(const char *format);
size_t ft_strlen(const char *s);
int ft_valid(char c);
int ft_display_format(char c, va_list args_infos); 
int ft_write_hex_adress(unsigned long int nbr, char *base, int first, int *count);
int ft_print_no_format(int c);
int ft_printf(const char *format, ...);
#endif