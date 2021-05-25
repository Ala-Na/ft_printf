# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 16:18:10 by elanna            #+#    #+#              #
#    Updated: 2021/05/25 22:42:57 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_SRCS	= ./libft/ft_atoi.c ./libft/ft_bzero.c \
./libft/ft_calloc.c ./libft/ft_isalnum.c \
./libft/ft_isalpha.c ./libft/ft_isascii.c \
./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c \
./libft/ft_memccpy.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c \
./libft/ft_putchar_fd.c ./libft/ft_putendl_fd.c \
./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c \
./libft/ft_strchr.c ./libft/ft_strdup.c ./libft/ft_strjoin.c \
./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c \
./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c \
./libft/ft_strrchr.c ./libft/ft_strtrim.c .//libft/ft_substr.c \
./libft/ft_tolower.c  ./libft/ft_toupper.c \
./libft/ft_lstadd_back.c  ./libft/ft_lstadd_front.c \
./libft/ft_lstclear.c ./libft/ft_lstdelone.c ./libft/ft_lstiter.c \
./libft/ft_lstlast.c ./libft/ft_lstmap.c ./libft/ft_lstnew.c \
./libft/ft_lstsize.c ./libft/ft_strtrim_ult_bonus.c \
./libft/get_next_line_bonus.c ./libft/get_next_line_utils_bonus.c \
./libft/ft_bintodec_bonus.c ./libft/ft_putchar_bonus.c \
./libft/ft_pow_bonus.c ./libft/ft_uitoa_bonus.c \
./libft/ft_uitobase_bonus.c ./libft/ft_hexaddr_bonus.c \
./libft/ft_llitoa_bonus.c ./libft/ft_ullitoa_bonus.c \
./libft/ft_dtoa_exp_bonus.c ./libft/ft_dtoa_frac_bonus.c \
./libft/ft_dtoa_ope_bonus.c ./libft/ft_dtoa_rounding_bonus.c \
./libft/ft_dtoa_shortrep_bonus.c ./libft/ft_ullitobase_bonus.c \
./libft/ft_dtoa_shortrep_utils_bonus.c ./libft/ft_print_bin_rep_bonus.c \
./libft/ft_dtoa_utils_bonus.c ./libft/ft_dtoa_bonus.c \
./libft/ft_ishexa_bonus.c ./libft/ft_putlenstr_fd_bonus.c

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

bonus:	fclean ${B_OBJS} ${L_OBJS}
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

