# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 02:28:43 by ccai              #+#    #+#              #
#    Updated: 2020/02/26 18:05:35 by ccai             ###   ########.fr        #
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
		${RM} ${OBJTS}
	
fclean : clean
		 ${RM} ${NAME}

re : 	fclean all
