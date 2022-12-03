SRCS		=	./srcs/p_a_b.c \
				./srcs/r_a_b.c \
				./srcs/rr_a_b.c \
				./srcs/s_a_b.c \
				./srcs/utils.c \
				./srcs/swap.c \
				./srcs/swapper.c \
				./srcs/utils_2.c \
				./srcs/utils_3.c \
				./srcs/utils_4.c

OBJS		= 	$(SRCS:.c=.o)

DEPS		= 	$(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

SWAP		=	swap

all:			$(SWAP)

.c.o :	
			$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SWAP):	${OBJS}
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS} -g3 -L./lib -lft -lprintf -lgnl -o $(SWAP)

clean:
			rm -rf ./srcs/*.o
			rm -rf ./srcs/*.d
			
fclean:		clean
			rm -rf $(SWAP) ./lib/*.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re