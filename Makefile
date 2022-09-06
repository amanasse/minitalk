SRCS    = 	sources/srcs_client/main_client.c\
		sources/libft/ft_strlen.c\
		sources/libft/ft_atoi.c\
		sources/libft/ft_bzero.c\
		sources/libft/ft_calloc.c\
		sources/libft/ft_isalnum.c\
		sources/libft/ft_isalpha.c\
		sources/libft/ft_isascii.c\
		sources/libft/ft_isdigit.c\
		sources/libft/ft_isprint.c\
		sources/libft/ft_memchr.c\
		sources/libft/ft_memcmp.c\
		sources/libft/ft_memcpy.c\
		sources/libft/ft_memmove.c\
		sources/libft/ft_memset.c\
		sources/libft/ft_strchr.c\
		sources/libft/ft_strlcat.c\
		sources/libft/ft_strlcpy.c\
		sources/libft/ft_strncmp.c\
		sources/libft/ft_strnstr.c\
		sources/libft/ft_strrchr.c\
		sources/libft/ft_tolower.c\
		sources/libft/ft_toupper.c\
		sources/libft/ft_strdup.c\
		sources/libft/ft_substr.c\
		sources/libft/ft_strjoin.c\
		sources/libft/ft_strtrim.c\
		sources/libft/ft_split.c\
		sources/libft/ft_itoa.c\
		sources/libft/ft_strmapi.c\
		sources/libft/ft_striteri.c\
		sources/libft/ft_putchar_fd.c\
		sources/libft/ft_putstr_fd.c\
		sources/libft/ft_putendl_fd.c\
		sources/libft/ft_putnbr_fd.c\
		sources/libft/ft_lstnew.c\
		sources/libft/ft_lstadd_front.c\
		sources/libft/ft_lstsize.c\
		sources/libft/ft_lstlast.c\
		sources/libft/ft_lstadd_back.c\
		sources/libft/ft_lstdelone.c\
		sources/libft/ft_lstclear.c\
		sources/libft/ft_lstiter.c\
		sources/libft/ft_lstmap.c\
		sources/ft_printf/ft_strlen.c\
		sources/ft_printf/ft_char.c\
		sources/ft_printf/count_nb.c\
		sources/ft_printf/count_hexa.c\
		sources/ft_printf/ft_putchar.c\
		sources/ft_printf/ft_putnbr_base_x_x.c\
		sources/ft_printf/ft_printf.c\
		sources/ft_printf/ft_putnbr_base.c\
		sources/ft_printf/ft_putnbr_d_i.c\
		sources/ft_printf/ft_putnbr_u.c\
		sources/ft_printf/ft_string.c\
		sources/ft_printf/count_u.c\
		sources/ft_printf/count_hexa_x_x.c\
		sources/gnl/get_next_line.c\
		sources/gnl/get_next_line_utils.c

SRCS2	=	sources/srcs_server/main_server.c\
		sources/srcs_server/server_utils.c\
		sources/libft/ft_strlen.c\
		sources/libft/ft_atoi.c\
		sources/libft/ft_bzero.c\
		sources/libft/ft_calloc.c\
		sources/libft/ft_isalnum.c\
		sources/libft/ft_isalpha.c\
		sources/libft/ft_isascii.c\
		sources/libft/ft_isdigit.c\
		sources/libft/ft_isprint.c\
		sources/libft/ft_memchr.c\
		sources/libft/ft_memcmp.c\
		sources/libft/ft_memcpy.c\
		sources/libft/ft_memmove.c\
		sources/libft/ft_memset.c\
		sources/libft/ft_strchr.c\
		sources/libft/ft_strlcat.c\
		sources/libft/ft_strlcpy.c\
		sources/libft/ft_strncmp.c\
		sources/libft/ft_strnstr.c\
		sources/libft/ft_strrchr.c\
		sources/libft/ft_tolower.c\
		sources/libft/ft_toupper.c\
		sources/libft/ft_strdup.c\
		sources/libft/ft_substr.c\
		sources/libft/ft_strjoin.c\
		sources/libft/ft_strtrim.c\
		sources/libft/ft_split.c\
		sources/libft/ft_itoa.c\
		sources/libft/ft_strmapi.c\
		sources/libft/ft_striteri.c\
		sources/libft/ft_putchar_fd.c\
		sources/libft/ft_putstr_fd.c\
		sources/libft/ft_putendl_fd.c\
		sources/libft/ft_putnbr_fd.c\
		sources/libft/ft_lstnew.c\
		sources/libft/ft_lstadd_front.c\
		sources/libft/ft_lstsize.c\
		sources/libft/ft_lstlast.c\
		sources/libft/ft_lstadd_back.c\
		sources/libft/ft_lstdelone.c\
		sources/libft/ft_lstclear.c\
		sources/libft/ft_lstiter.c\
		sources/libft/ft_lstmap.c\
		sources/ft_printf/ft_strlen.c\
		sources/ft_printf/ft_char.c\
		sources/ft_printf/count_nb.c\
		sources/ft_printf/count_hexa.c\
		sources/ft_printf/ft_putchar.c\
		sources/ft_printf/ft_putnbr_base_x_x.c\
		sources/ft_printf/ft_printf.c\
		sources/ft_printf/ft_putnbr_base.c\
		sources/ft_printf/ft_putnbr_d_i.c\
		sources/ft_printf/ft_putnbr_u.c\
		sources/ft_printf/ft_string.c\
		sources/ft_printf/count_u.c\
		sources/ft_printf/count_hexa_x_x.c\
		sources/gnl/get_next_line.c\
		sources/gnl/get_next_line_utils.c

DIR_SRC = sources/
OBJ	= ${SRCS:.c=.o}
OBJ2 = ${SRCS2:.c=.o}
DIR_OBJ = sources/objs/
OBJS = $(addprefix $(DIR_OBJ), $(OBJ))
OBJS2 = $(addprefix $(DIR_OBJ), $(OBJ2))
DEP = ${SRCS:.c=.d}
DEP2 = ${SRCS2:.c=.d}
DEPS = $(addprefix $(DIR_OBJ), $(DEP))
DEPS2 = $(addprefix $(DIR_OBJ), $(DEP2))

HEADERS	= -I includes
CC		= gcc
CFLAGS	= -MMD -Wall -Wextra -Werror

all :		client server

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	${CC} ${CFLAGS} -c $< ${HEADERS} -o $@

client :	${OBJS} 
			${CC} -o client ${CFLAGS} ${OBJS} 

server :	${OBJS2}
			${CC} -o server ${CFLAGS} ${OBJS2} 

clean:
			rm -f ${OBJS} ${OBJS2} ${DEPS} ${DEPS2}

fclean:		clean
			rm -f client server

re:			fclean all

.PHONY: all clean fclean re

-include ${DEPS} ${DEPS2} 