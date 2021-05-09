/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:48 by elanna            #+#    #+#             */
/*   Updated: 2021/05/09 23:36:17 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/* UNIQUEMENT POUR LES TESTS !!! A SUPPRIMER !!! */
# include <stdio.h>
# include <math.h>

/* Variables globales pour rendre aisée la comparaison, définies dans ft_parsing.c */
extern char	*FLAGS;
extern char	*CONVERSION_SPECIFIER;

/* Structure nécessaire pour stocker les informations
relatives au format */
typedef struct	s_infos
{
	char	valid;
	char	*invalid;
	char	minus;
	char	zero;
	char	hash;
	char	plus;
	char	space;
	int	field;
	int	precision;
	char	length;
	char	converter;
	int	format_size;
}		t_infos;

/* Union nécessaire pour la conversion d'un double
en unsigned long long dans ft_dtoa.c */
typedef union
{
	double			d;
	unsigned long long	l;
}	dbl_union;

/* Fonctions issues de libft (ft_libft_needed.c) */
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int	ft_isdigit(int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Fonctions pouvant être ajoutées à libft (ft_newft_libft.c) */
unsigned long long	ft_pow(unsigned long long nb, int power);
char	*ft_uitoa(unsigned int n);
char	*ft_uitobase(unsigned int n, char *base);
char	*ft_hexaddr(void *addr);
char	*ft_llitoa(long long n);
char	*ft_ullitoa(unsigned long long n);
char	*ft_ullitobase(unsigned long long n, char *base);
void	ft_print_bin_rep(size_t const size, void const *ptr);
unsigned long long	ft_bintodec(unsigned long long bin, int start);

/* Fonctions nécessaires à dtoa (ft_dtoa.c) */
char	*add_chars_to_mall_str(char *mall_str, const char *cst,
char front_or_end);
void	stock_fill(char **stock_frac, char *to_add, int s_frac,
int s_add);
char	*stock_init(char *stock_frac, char *to_add, char int_or_frac);
char	*apply_dtwo_pten(unsigned int i);
unsigned long long	convert_mant_to_frac(unsigned long long mant, short exp,
unsigned int *i);
char	*get_frac_part(unsigned long long mant, short exp);
char	*del_front_zero(char *to_add, int approx_size);
void	apply_ptwo_fill(char **to_add, int approx_size);
void	apply_ptwo_init(short exp, char **to_add);
char	*get_big_int(unsigned long long int_part, short exp);
char	*get_int_part(unsigned long long mant, short exp);
void	bankers_or_usual_rounding(char **number, char **frac_part, unsigned i);
void	do_rounding(char **number, char *frac_part,
unsigned i, unsigned size);
char	*get_round_number(char *int_part, char *frac_part, int precision);
char	*get_dtoa_number(unsigned long long mant, short exp, int precision, int show_exp);
char	*ft_dtoa(double dbl, int precision, int show_exp);

/* Fonctions nécessaires pour le dtoa with exp, réutilise certaines fonctions de 
ft_dtoa.c (ft_exp.c) */
char	*add_exp(int exp, char *number, int shortest_rep);
void	fill_round_exp_number(char **number, int size, int num_size, int limit_size);
void	exp_rounding_operation(char **number, int *exp, int i);
void	do_exp_rounding(char **number, int *exp, int precision);
char	*get_round_exp_number(char *int_part, char *frac_part, int precision);

/* Fonctions pour la plus courte representation selon dtoa (ft_check_exp.c) */
void	del_last_zero(char **number, int size);
int	exp_after_rounding(char **number, int exp, int precision, int int_size);
void	adjust_precision(char *int_part, char *frac_part, int *precision);
void	adjust_number(char **number);
char	*check_exp_for_format(int exp, char *int_part, char *frac_part,
int precision);
char	*get_number_shortest_rep(char *int_part, char *frac_part, int precision);
char	*get_dtoa_shortest_rep(unsigned long long mant, short exp, int precision);
char	*ft_dtoa_shortest_rep(double dbl, int precision);


/* Fonctions relatives à la structure (ft_struct.c) */
t_infos	*init_infos_struct();

/* Fonctions relatives au parsing (ft_parsing.c) */
t_infos	*parse_format(const char **format, va_list *infos);
char	*parse_flags(t_infos *infos_struct, char *str);
char	*parse_field_width(va_list *infos, t_infos *infos_struct, char *str);
void	stock_infos_read(t_infos *infos_struct, char c);
char	*parse_precision(t_infos *infos_struct, char *str);
char	*parse_length(t_infos *infos_struct, char *str);
char	*parse_converter(t_infos *infos_struct, char *str);
void	stock_infos_parsed(t_infos *infos_struct, char c);

/* Fonctions relatives a la translation (ft_translation.c) */
char	*ft_translate_format(t_infos *infos_struct, va_list *infos);

/* Fonctions relatives aux convertersi, toutes fournissent des str malloced */
char	*c_converter(va_list *infos);
char	*s_converter(va_list *infos);
char	*i_d_converter(va_list *infos, char length);
char	*percent_converter();
char	*u_converter(va_list *infos, char length);
char	*x_converter(va_list *infos, char length, char hash);
char	*X_converter(va_list *infos, char length, char hash);
char	*p_converter(va_list *infos);
char	*f_converter(va_list *infos, t_infos *infos_struct);
char	*e_converter(va_list *infos, t_infos *infos_struct);
char	*g_converter(va_list *infos, t_infos *infos_struct);
char	*n_converter(char *str);

/* Fonctions relatives au flags */
char	*apply_hash(t_infos *infos_struct, char *str);

/* Fonctions du fichier principal (ft_printf.c) */
int	ft_printf(const char *format, ...);

#endif
