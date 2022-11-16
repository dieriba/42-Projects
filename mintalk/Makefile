SRC_CLIENT	= client.c utils.c

SRC_SERVER	= server.c utils.c

OBJS_SERVER	= $(SRC_SERVER:.c=.o)

OBJS_CLIENT	= $(SRC_CLIENT:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

all:		$(SERVER) $(CLIENT)

.c.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SERVER):	${OBJS_SERVER}
			make -C ./libft fclean
			make -C ./libft
			make -C ./libft clean
			cp ./libft/libft.a .
			$(CC) $(CFLAGS) ${OBJS_SERVER} -L. -lft -o $(SERVER)

$(CLIENT):	${OBJS_CLIENT}	
			make -C ./libft fclean
			make -C ./libft
			make -C ./libft clean
			cp ./libft/libft.a .
			$(CC) $(CFLAGS) $(OBJS_CLIENT) -L. -lft -o $(CLIENT)

clean:
			rm -rf *.o

fclean:		clean
			rm -rf $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re