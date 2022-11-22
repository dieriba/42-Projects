SRCS		=	./srcs/pipex.c ./srcs/init.c ./srcs/check.c ./srcs/errors_handling.c ./srcs/path.c ./srcs/pipe.c

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

PIPEX		=	pipex

all:		$(PIPEX)

.c.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PIPEX):	${OBJS}
			make -C ./libft
			cp ./libft/libft.a .
			$(CC) $(CFLAGS) ${OBJS} -g3 -L. -lft -lprintf -o $(PIPEX)

clean:
			rm -rf *.o
			rm -rf *.d
			
fclean:		clean
			rm -rf $(PIPEX) ./lib/libft.a ./lib/libprintf.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re