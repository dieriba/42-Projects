NAME		=	libprintf_bonus.a

SRCS 		=	ft_printf_bonus.c \
					srcs_bonus/ft_putchar.c \
					srcs_bonus/ft_print_no_format.c \
					srcs_bonus/ft_strlen.c \
					srcs_bonus/ft_print_zero.c \
					srcs_bonus/ft_print_plus.c \
					srcs_bonus/ft_print_space.c \
					srcs_bonus/ft_print_minus.c \
					srcs_bonus/ft_print_hash.c \
					srcs_bonus/ft_print_char.c \
					srcs_bonus/ft_isdigit.c \
					srcs_bonus/ft_isspace.c \
					srcs_bonus/ft_checker.c \
					srcs_bonus/ft_putnb_uns.c \
					srcs_bonus/ft_putnbr.c \
					srcs_bonus/ft_putnbr_base_hexa.c \
					srcs_bonus/ft_putstr_fd.c \
					srcs_bonus/ft_write_add.c \

OBJS		=	${SRCS:.c=.o}
INCLUDES	=	-I includes_bonus

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re