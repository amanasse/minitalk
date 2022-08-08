SRCS    = 	main_client.c\
		libft/ft_strlen.c\
		libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_strchr.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\
		libft/ft_strdup.c\
		libft/ft_substr.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_split.c\
		libft/ft_itoa.c\
		libft/ft_strmapi.c\
		libft/ft_striteri.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_lstnew.c\
		libft/ft_lstadd_front.c\
		libft/ft_lstsize.c\
		libft/ft_lstlast.c\
		libft/ft_lstadd_back.c\
		libft/ft_lstdelone.c\
		libft/ft_lstclear.c\
		libft/ft_lstiter.c\
		libft/ft_lstmap.c\
		ft_printf/ft_strlen.c\
		ft_printf/ft_char.c\
		ft_printf/count_nb.c\
		ft_printf/count_hexa.c\
		ft_printf/ft_putchar.c\
		ft_printf/ft_putnbr_base_x_x.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_putnbr_base.c\
		ft_printf/ft_putnbr_d_i.c\
		ft_printf/ft_putnbr_u.c\
		ft_printf/ft_string.c\
		ft_printf/count_u.c\
		ft_printf/count_hexa_x_x.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

SRCS2	=	main_serveur.c\
		libft/ft_strlen.c\
		libft/ft_atoi.c\
		libft/ft_bzero.c\
		libft/ft_calloc.c\
		libft/ft_isalnum.c\
		libft/ft_isalpha.c\
		libft/ft_isascii.c\
		libft/ft_isdigit.c\
		libft/ft_isprint.c\
		libft/ft_memchr.c\
		libft/ft_memcmp.c\
		libft/ft_memcpy.c\
		libft/ft_memmove.c\
		libft/ft_memset.c\
		libft/ft_strchr.c\
		libft/ft_strlcat.c\
		libft/ft_strlcpy.c\
		libft/ft_strncmp.c\
		libft/ft_strnstr.c\
		libft/ft_strrchr.c\
		libft/ft_tolower.c\
		libft/ft_toupper.c\
		libft/ft_strdup.c\
		libft/ft_substr.c\
		libft/ft_strjoin.c\
		libft/ft_strtrim.c\
		libft/ft_split.c\
		libft/ft_itoa.c\
		libft/ft_strmapi.c\
		libft/ft_striteri.c\
		libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c\
		libft/ft_putendl_fd.c\
		libft/ft_putnbr_fd.c\
		libft/ft_lstnew.c\
		libft/ft_lstadd_front.c\
		libft/ft_lstsize.c\
		libft/ft_lstlast.c\
		libft/ft_lstadd_back.c\
		libft/ft_lstdelone.c\
		libft/ft_lstclear.c\
		libft/ft_lstiter.c\
		libft/ft_lstmap.c\
		ft_printf/ft_strlen.c\
		ft_printf/ft_char.c\
		ft_printf/count_nb.c\
		ft_printf/count_hexa.c\
		ft_printf/ft_putchar.c\
		ft_printf/ft_putnbr_base_x_x.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_putnbr_base.c\
		ft_printf/ft_putnbr_d_i.c\
		ft_printf/ft_putnbr_u.c\
		ft_printf/ft_string.c\
		ft_printf/count_u.c\
		ft_printf/count_hexa_x_x.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}
OBJS2	= ${SRCS2:.c=.o}
HEADERS	= "minitalk.h"
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all :		client serveur

.c.o:
	${CC} ${CFLAGS} -c $< -I includes -o ${<:.c=.o}

client :	${OBJS}
			${CC} -o client ${CFLAGS} ${OBJS} 

serveur :	${OBJS2}
			${CC} -o serveur ${CFLAGS} ${OBJS2} 


clean:
			rm -f ${OBJS} ${OBJS2}

fclean:		clean
			rm -f client serveur

re:			fclean all

.PHONY: all clean fclean re