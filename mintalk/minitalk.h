#ifndef COMMON_H
#define COMMON_H

#define SA struct sigaction
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(char *s, int fd);
int ft_atoi(const char *nptr);
size_t ft_strlen(char *str);
#endif