# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/06/17 20:09:19 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#M_SRCS = ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_2.c \
#./srcs/ft_translate_flags.c  ./srcs/ft_printf.c \
#./srcs/ft_translation.c ./srcs/ft_field_and_precision.c \
#./srcs/ft_flags_parsing.c ./srcs/ft_parsing.c \
#./srcs/ft_struct.c 

B_SRCS = ./bonus/ft_converter_types_1_bonus.c ./bonus/ft_converter_types_4_bonus.c \
./bonus/ft_flags_parsing_bonus.c  ./bonus/ft_struct_bonus.c \
./bonus/ft_translate_flags_others_bonus.c ./bonus/ft_converter_types_2_bonus.c \
./bonus/ft_field_and_precision_bonus.c ./bonus/ft_parsing_bonus.c \
./bonus/ft_translation_bonus.c ./bonus/ft_get_infos_bonus.c \
./bonus/ft_converter_types_3_bonus.c ./bonus/ft_flags_bonus.c ./bonus/ft_printf_bonus.c \
./bonus/ft_translate_flags_bonus.c ./bonus/ft_translation_wchar_bonus.c \
./bonus/ft_apply_hash_1.c ./bonus/ft_apply_hash_2.c

HEADERS_FILE = includes

#M_OBJS	= ${M_SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= libftprintf.a

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

%.o: %.c
		${CC} -g ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<

all:		${NAME}

libft.a:
		make -C ./libft
		cp ./libft/libft.a ./${NAME}


#Remettre M_OBJS au lieu de B_OBJS
${NAME}:	${B_OBJS} libft.a
		ar rcs ${NAME} ${B_OBJS}

bonus:		${NAME}

#test:		
#		gcc -g test.c libftprintf.a -I includes
#		valgrind ./a.out

clean:
		rm -f ${B_OBJS}
		make clean -C ./libft

fclean: 	clean
		rm -f ${NAME}
		make fclean -C ./libft

re:		fclean all

.PHONY: all clean re 

