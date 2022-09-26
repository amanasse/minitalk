SRCS    = 	main_client.c

SRCS2	=	main_server.c\
			server_utils.c

DIR_SRC_CLIENT = ./sources/srcs_client/
DIR_SRC_SERVER = ./sources/srcs_server/
OBJ	= ${SRCS:.c=.o}
OBJ2 = ${SRCS2:.c=.o}
DIR_OBJ = sources/objs/
OBJS = $(addprefix $(DIR_OBJ), $(OBJ))
OBJS2 = $(addprefix $(DIR_OBJ), $(OBJ2))
DEP = ${SRCS:.c=.d}
DEP2 = ${SRCS2:.c=.d}
DEPS = $(addprefix $(DIR_OBJ), $(DEP))
DEPS2 = $(addprefix $(DIR_OBJ), $(DEP2))
NAME = minitalk

HEADERS	= -I includes
CC		= gcc
CFLAGS	= -D TIME_TO_SLEEP=180 -MMD -Wall -Wextra -Werror

${NAME} : client server

client :	${OBJS}
			make -C ./sources/libft
			${CC} ${CFLAGS} ${OBJS} ./sources/libft/libft.a -o client 

server :	${OBJS2}
			make -C ./sources/libft
			${CC} ${CFLAGS} ${OBJS2} ./sources/libft/libft.a -o server

all :		client server

clean:
			rm -f ${OBJS} ${OBJS2} ${DEPS} ${DEPS2}
			make -C ./sources/libft clean

fclean:		clean
			rm -f client server
			make -C ./sources/libft fclean

re:			fclean all

$(DIR_OBJ)%.o: $(DIR_SRC_CLIENT)%.c 
	${CC} ${CFLAGS} -c $< ${HEADERS} -o $@

$(DIR_OBJ)%.o: $(DIR_SRC_SERVER)%.c 
	${CC} ${CFLAGS} -c $< ${HEADERS} -o $@

-include ${DEPS} ${DEPS2}

.PHONY: all clean fclean re