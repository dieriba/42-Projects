#ifndef PUSH_H
#define PUSH_H 

#include "ft_printf.h"
typedef struct t_stack
{
    int     data;
    t_stack *next;
} t_stack;

#endif 