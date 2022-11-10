NAME		=	libprintf.a

SRCS 		=	ft_printf.c \
					ft_putchar.c \
					ft_print_no_format.c \
					ft_strlen.c \
					ft_checker.c \
					ft_display_format.c \
					ft_putnb_uns.c \
					ft_putnbr.c \
					ft_putnbr_base_hexa.c \
					ft_putstr_fd.c \
					ft_write_add.c \

OBJS		=	${SRCS:.c=.o}
INCLUDES	=	-I includes

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