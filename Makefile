# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/06/18 00:05:45 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_converter_types_1.c \
./srcs/ft_converter_types_4.c \
./srcs/ft_flags_parsing.c \
./srcs/ft_struct.c \
./srcs/ft_translate_flags_others.c \
./srcs/ft_converter_types_2.c \
./srcs/ft_field_and_precision.c \
./srcs/ft_parsing.c \
./srcs/ft_translation.c \
./srcs/ft_get_infos.c \
./srcs/ft_converter_types_3.c \
./srcs/ft_flags.c \
./srcs/ft_printf.c \
./srcs/ft_translate_flags.c \
./srcs/ft_translation_wchar.c \
./srcs/ft_apply_hash_1.c \
./srcs/ft_apply_hash_2.c

HEADERS_FILE = includes

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
		${CC} -g ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<

all:		${NAME}

libft.a:	
		make -C ./libft
		cp ./libft/libft.a ./${NAME}


${NAME}:	libft.a ${OBJS}
		ar rcs ${NAME} ${OBJS}

bonus:		${NAME}

clean:
		rm -f ${OBJS}
		make clean -C ./libft

fclean: 	clean
		rm -f ${NAME}
		make fclean -C ./libft

re:		fclean all

.PHONY: all clean re 

