# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 11:20:45 by amassey           #+#    #+#              #
#    Updated: 2020/02/27 13:11:51 by amassey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = includes/

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o} -I${HEADER}

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
		${RM} ${OBJS}

fclean : clean
		 ${RM} ${NAME}

re : 	fclean all
