# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/05/31 18:06:43 by anadege          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M_SRCS = ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_2.c \
./srcs/ft_translate_flags.c  ./srcs/ft_printf.c \
./srcs/ft_translation.c ./srcs/ft_field_and_precision.c \
./srcs/ft_flags_parsing.c ./srcs/ft_parsing.c \
./srcs/ft_struct.c 

B_SRCS = ./bonus/ft_converter_types_1_bonus.c ./bonus/ft_converter_types_4_bonus.c \
./bonus/ft_flags_parsing_bonus.c  ./bonus/ft_struct_bonus.c \
./bonus/ft_translate_flags_others_bonus.c ./bonus/ft_converter_types_2_bonus.c \
./bonus/ft_field_and_precision_bonus.c ./bonus/ft_parsing_bonus.c \
./bonus/ft_translation_bonus.c ./bonus/ft_get_infos_bonus.c \
./bonus/ft_converter_types_3_bonus.c ./bonus/ft_flags_bonus.c ./bonus/ft_printf_bonus.c \
./bonus/ft_translate_flags_bonus.c ./bonus/ft_translation_wchar_bonus.c \
./bonus/ft_apply_hash_1.c ./bonus/ft_apply_hash_2.c

HEADERS_FILE = includes

M_OBJS	= ${M_SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<

all:	${NAME}

libft.a:
		make -C ./libft
		cp ./libft/libft.a ./${NAME}


${NAME}:	${M_OBJS} libft.a
		ar rcs ${NAME} ${M_OBJS}

bonus:		fclean ${B_OBJS} libft.a
		ar rcs ${NAME} ${B_OBJS}

clean:
		rm -f ${M_OBJS} ${B_OBJS}
		make clean -C ./libft

fclean: 	clean
		rm -f ${NAME} libft.a
		make fclean -C ./libft

re:		fclean all

.PHONY: all clean re 

