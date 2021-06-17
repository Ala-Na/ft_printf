/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:06:44 by elanna            #+#    #+#             */
/*   Updated: 2021/05/30 00:01:39 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <wchar.h>
# include "libft.h"

void					ft_putlenstr_fd(char *s, int fd,
							size_t len);
char					*ft_strtrim_ult(char const *s1,
							char const *set);
void					ft_putchar(char c);
unsigned long long		ft_pow(unsigned long long nb, int power);
char					*ft_uitoa(unsigned int n);
char					*ft_uitobase(unsigned int n,
							char *base);
char					*ft_hexaddr(void *addr);
char					*ft_llitoa(long long n);
char					*ft_ullitoa(unsigned long long n);
char					*ft_ullitobase(unsigned long long n,
							char *base);
void					ft_print_bin_rep(size_t const size,
							void const *ptr);
unsigned long long		ft_bintodec(unsigned long long bin, int start);
int						ft_ishexa(int c);

/*
** Following : All prototypes functions for get_next_line-like.
*/

char					*ft_strdup(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strchr_for_gnl(char *s, int c, int replace);
t_content				*ft_contnew(char *buffer, int fd);
void					ft_contadd_back(t_content **alst, t_content *new);
void					ft_delcont(int fd, t_content **content);
t_content				*ft_lstchr_fd(t_content **lst, int fd);
int						get_content_line(int fd, char **line, ssize_t rd,
							t_content **cont);
void					fill_content_struct(t_content **content, char *buffer,
							int fd);
int						get_next_line(int fd, char **line);

/*
** Following : Functions to print wide characters.
*/
size_t					ft_wcrtomb(char *s, wchar_t wc, mbstate_t *ps);
int						ft_putwstr_fd(wchar_t *w_str, int fd);
int						ft_putlenwstr_fd(wchar_t *w_str,
							int fd, size_t len);

/*
** Following : All prototypes for functions dtoa-like.
** 3 conversions of double to ascii are possible, as those functions
** were made to be used in ft_printf as 'f' (float/double), 'e' (float/double
** with exponent) and 'g' (either f or e, depending of the decimal exponent).
** Some functions of libft are needed to make it work.
** They can be added to libft though it's not well optimised at all.
** For each of them, the precision (number of digits after the '.' or number of
** significants digits) need to be specified.
** Note that a double (64 bits) or float (32 bits) can be 'imprecise' because of
** the way it is stocked inside the memory.
** The number may vary depending of the precision because of that,
** and also because it's rounded.
*/

/*
** Union needed for convertion from double to
** unsigned long long.
*/

typedef union u_dbl_union
{
	double				d;
	unsigned long long	l;
}						t_dbl_union;

/*
** Functions needed for 'f' and useful for others formats
** In : ft_dtoa_bonus.c, ft_dtoa_rounding_bonus.c,
** ft_dtoa_frac_bonus.c & ft_dtoa_ope_bonus.c
*/

char					*apply_dtwo_pten(unsigned int i);
void					apply_ptwo_fill(char **to_add,
							int approx_size);
void					apply_ptwo_init(short exp,
							char **to_add);

char					*del_front_zero(char *to_add,
							int approx_size);
char					*add_chars_to_mall_str(char *mall_str,
							const char *cst, char front_or_end);
void					stock_fill(char **stock_part,
							char *to_add, int s_part, int s_add);
char					*stock_init(char *stock_part,
							char *to_add, char int_or_frac);

unsigned long long		convert_mant_to_frac(unsigned long long mant,
							short exp, unsigned int *i);
char					*get_frac_part(unsigned long long mant,
							short exp);

void					bankers_or_usual_rounding(char **number,
							char **frac_part, unsigned int i);
void					do_rounding(char **number,
							char *frac_part, unsigned i, unsigned size);
char					*get_round_number(char *int_part,
							char *frac_part, int precision);
char					*get_big_int(unsigned long long int_part,
							short exp);
char					*get_int_part(unsigned long long mant,
							short exp);
char					*get_dtoa_number(unsigned long long mant,
							short exp, int precision, int show_exp);
char					*ft_dtoa(double dbl, int precision,
							int show_exp);

/*
** Functions needed for 'e' format
** In : ft_dtoa_exp_bonus.c
*/

char					*add_exp(int exp, char *number,
							int shortest_rep);
void					fill_round_exp_number(char **number,
							int size, int limit_size);
void					exp_rounding_operation(char **number,
							int *exp, int i);
void					do_exp_rounding(char **number, int *exp,
							int precision);
char					*get_round_exp_number(char *int_part,
							char *frac_part, int precision);

/*
** Functions needed for 'g' format
** In : ft_dtoa_shortrep_bonus.c
** & ft_dtoa_shortrep_utils_bonus.c
*/

void					del_last_zero(char **number, int size);
int						exp_after_rounding(char **number, int exp,
							int precision, int int_size);
void					adjust_precision(char *int_part,
							char *frac_part, int *precision);
void					adjust_number(char **number);

char					*check_exp_for_format(int exp, char *int_part,
							char *frac_part, int precision);
char					*get_number_shortest_rep(char *int_part,
							char *frac_part, int precision);
char					*get_dtoa_shortest_rep(unsigned long long mant,
							short exp, int precision);
char					*ft_dtoa_shortest_rep(double dbl,
							int precision);

#endif
