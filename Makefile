# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/05/14 17:56:54 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_3.c \
./srcs/ft_flag_hash.c ./srcs/ft_others_flags.c  ./srcs/ft_printf.c \
./srcs/ft_translation.c ./srcs/ft_converter_types_2.c \
./srcs/ft_field_and_precision.c ./srcs/ft_flags_parsing.c ./srcs/ft_parsing.c \
./srcs/ft_struct.c

HEADERS	= includes

OBJS	= ${SRCS:.c=.o}

NAME	= ft_printf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
	${CC} -I ${HEADERS} -o ${NAME} ${OBJS} libft.a

debug:	${OBJS}
	${CC} -I ${HEADERS} -g -o ${NAME} ${OBJS} libft.a
	valgrind ./${NAME}

leaks: 	${OBJS}
	${CC} -I ${HEADERS} -g -o ${NAME} ${OBJS} libft.a
	valgrind --leak-check=full ./${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} ${TEMP}

re:	fclean all

.PHONY: all clean fclean re

