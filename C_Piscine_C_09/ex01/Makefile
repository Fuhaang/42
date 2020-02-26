NAME	= libft.a

SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc
RM		= /bin/rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -c ${SRCS}
		   	ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
