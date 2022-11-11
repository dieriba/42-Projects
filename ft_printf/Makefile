NAME		=	libftprintf.a

SRCS 		=	ft_printf.c \
				srcs/ft_putchar.c \
				srcs/ft_atoi.c \
				srcs/ft_strlen.c \
				srcs/ft_print_zero.c \
				srcs/ft_print_plus.c \
				srcs/ft_print_space.c \
				srcs/ft_print_minus.c \
				srcs/ft_print_hash.c \
				srcs/ft_print_char.c \
				srcs/ft_isdigit.c \
				srcs/ft_isspace.c \
				srcs/ft_checker.c \
				srcs/ft_putnb_uns.c \
				srcs/ft_putnbr.c \
				srcs/ft_putnbr_base_hexa.c \
				srcs/ft_putstr_fd.c \
				srcs/ft_write_add.c \

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	-I includes

BONUS		=	ft_printf.c \
				srcs/ft_putchar.c \
				srcs/ft_print_no_format.c \
				srcs/ft_strlen.c \
				srcs/ft_print_zero.c \
				srcs/ft_print_plus.c \
				srcs/ft_print_space.c \
				srcs/ft_print_minus.c \
				srcs/ft_print_hash.c \
				srcs/ft_print_char.c \
				srcs/ft_isdigit.c \
				srcs/ft_isspace.c \
				srcs/ft_checker.c \
				srcs/ft_putnb_uns.c \
				srcs/ft_putnbr.c \
				srcs/ft_putnbr_base_hexa.c \
				srcs/ft_putstr_fd.c \
				srcs/ft_write_add.c \

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

bonus : ${NAME}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re