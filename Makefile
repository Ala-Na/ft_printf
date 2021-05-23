# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/05/21 17:49:30 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_SRCS	= ./srcs/libft/ft_atoi.c ./srcs/libft/ft_bzero.c \
./srcs/libft/ft_calloc.c ./srcs/libft/ft_isalnum.c \
./srcs/libft/ft_isalpha.c ./srcs/libft/ft_isascii.c \
./srcs/libft/ft_isdigit.c ./srcs/libft/ft_isprint.c ./srcs/libft/ft_itoa.c \
./srcs/libft/ft_memccpy.c ./srcs/libft/ft_memchr.c ./srcs/libft/ft_memcmp.c \
./srcs/libft/ft_memcpy.c ./srcs/libft/ft_memmove.c ./srcs/libft/ft_memset.c \
./srcs/libft/ft_putchar_fd.c ./srcs/libft/ft_putendl_fd.c \
./srcs/libft/ft_putnbr_fd.c ./srcs/libft/ft_putstr_fd.c ./srcs/libft/ft_split.c \
./srcs/libft/ft_strchr.c ./srcs/libft/ft_strdup.c ./srcs/libft/ft_strjoin.c \
./srcs/libft/ft_strlcat.c ./srcs/libft/ft_strlcpy.c ./srcs/libft/ft_strlen.c \
./srcs/libft/ft_strmapi.c ./srcs/libft/ft_strncmp.c ./srcs/libft/ft_strnstr.c \
./srcs/libft/ft_strrchr.c ./srcs/libft/ft_strtrim.c ./srcs/libft/ft_substr.c \
./srcs/libft/ft_tolower.c  ./srcs/libft/ft_toupper.c \
./srcs/libft/ft_lstadd_back.c  ./srcs/libft/ft_lstadd_front.c \
./srcs/libft/ft_lstclear.c ./srcs/libft/ft_lstdelone.c ./srcs/libft/ft_lstiter.c \
./srcs/libft/ft_lstlast.c ./srcs/libft/ft_lstmap.c ./srcs/libft/ft_lstnew.c \
./srcs/libft/ft_lstsize.c ./srcs/libft/ft_strtrim_ult_bonus.c \
./srcs/libft/get_next_line_bonus.c ./srcs/libft/get_next_line_utils_bonus.c \
./srcs/libft/ft_bintodec_bonus.c ./srcs/libft/ft_putchar_bonus.c \
./srcs/libft/ft_pow_bonus.c ./srcs/libft/ft_uitoa_bonus.c \
./srcs/libft/ft_uitobase_bonus.c ./srcs/libft/ft_hexaddr_bonus.c \
./srcs/libft/ft_llitoa_bonus.c ./srcs/libft/ft_ullitoa_bonus.c \
./srcs/libft/ft_dtoa_exp_bonus.c ./srcs/libft/ft_dtoa_frac_bonus.c \
./srcs/libft/ft_dtoa_ope_bonus.c ./srcs/libft/ft_dtoa_rounding_bonus.c \
./srcs/libft/ft_dtoa_shortrep_bonus.c ./srcs/libft/ft_ullitobase_bonus.c \
./srcs/libft/ft_dtoa_shortrep_utils_bonus.c ./srcs/libft/ft_print_bin_rep_bonus.c \
./srcs/libft/ft_dtoa_utils_bonus.c ./srcs/libft/ft_dtoa_bonus.c \
./srcs/libft/ft_ishexa_bonus.c ./srcs/libft/ft_putlenstr_fd_bonus.c

SRCS = ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_2.c \
./srcs/ft_translate_flags.c  ./srcs/ft_printf.c \
./srcs/ft_translation.c ./srcs/ft_field_and_precision.c \
./srcs/ft_flags_parsing.c ./srcs/ft_parsing.c \
./srcs/ft_struct.c 

B_SRCS = ./srcs/ft_converter_types_1.c ./srcs/ft_converter_types_2.c \
./srcs/ft_translate_flags.c  ./srcs/ft_printf.c \
./srcs/ft_translation_bonus.c ./srcs/ft_field_and_precision.c \
./srcs/ft_struct.c ./srcs/ft_converter_types_bonus.c \
./srcs/ft_flags_parsing_bonus.c ./srcs/ft_translate_flags_bonus.c \
./srcs/ft_translation_bonus.c ./srcs/ft_translate_flag_hash_bonus.c \
./srcs/ft_flags_bonus.c ./srcs/ft_parsing_bonus.c

TEST = ./test.c

HEADERS	= includes

L_OBJS	= ${L_SRCS:.c=.o}

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= libftprintf.a

FUN	= ft_printf

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS} ${L_OBJS}
	ar rcs ${NAME} ${OBJS} ${L_OBJS}

bonus:	${B_OBJS} ${L_OBJS}
	ar rcs ${NAME} ${L_OBJS} ${B_OBJS}

prep:	${NAME}
	${CC} -I ${HEADERS} -g -o ${FUN} test.c ${NAME}

prep_b:	bonus
	${CC} -I ${HEADERS} -g -o ${FUN} test.c ${NAME}

debug:	prep clean
	valgrind ./${FUN}

bebug:	prep_b clean
	valgrind ./${FUN}

leaks: 	prep clean
	valgrind --leak-check=full ./${FUN}

clean:
	rm -f ${OBJS} ${L_OBJS} ${B_OBJS}

fclean: clean
	rm -f ${NAME} ${TEMP}

cclean:	clean
	rm -f ${FUN}

re:	fclean all

.PHONY: all clean fclean re

