# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/05/26 12:12:52 by anadege          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_2.c \
./srcs/ft_translate_flags.c  ./srcs/ft_printf.c \
./srcs/ft_translation.c ./srcs/ft_field_and_precision.c \
./srcs/ft_flags_parsing.c ./srcs/ft_parsing.c \
./srcs/ft_struct.c 

B_SRCS = ./bonus/ft_converter_types_1_bonus.c ./bonus/ft_converter_types_4_bonus.c \
./bonus/ft_flags_parsing_bonus.c  ./bonus/ft_struct_bonus.c \
./bonus/ft_translate_flags_others_bonus.c ./bonus/ft_converter_types_2_bonus.c \
./bonus/ft_field_and_precision_bonus.c ./bonus/ft_parsing_bonus.c \
./bonus/ft_translate_flag_hash_bonus.c ./bonus/ft_translation_bonus.c \
./bonus/ft_converter_types_3_bonus.c ./bonus/ft_flags_bonus.c ./bonus/ft_printf_bonus.c \
./bonus/ft_translate_flags_bonus.c ./bonus/ft_translation_wchar_bonus.c


TEST = ./test.c

HEADERS	= includes

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= libftprintf.a

FUN	= ft_printf

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ./libft
			cp ./libft/libft.a ./$(NAME)
			ar rcs ${NAME} ${OBJS}

bonus:		fclean ${B_OBJS}
			make -C ./libft
			cp ./libft/libft.a ./$(NAME)
			ar rcs ${NAME} ${B_OBJS}

prep:		${NAME}
			${CC} -I ${HEADERS} -g -o ${FUN} test.c ${NAME}

prep_b:		bonus
			${CC} -I ${HEADERS} -g -o ${FUN} test.c ${NAME}

macdebug:	prep clean
			./${FUN}

macbebug:	prep_b clean
			./${FUN}

debug:		prep clean
			valgrind ./${FUN}

bebug:		prep_b clean
			valgrind ./${FUN}

leaks: 		prep clean
		valgrind --leak-check=full ./${FUN}

clean:
			rm -f ${OBJS} ${B_OBJS}

fclean: 	clean
			rm -f ${NAME}

cclean:		clean
			rm -f ${FUN}

re:			fclean all

.PHONY: all clean fclean re $(NAME) bonus

