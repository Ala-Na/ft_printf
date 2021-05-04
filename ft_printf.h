/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:48 by elanna            #+#    #+#             */
/*   Updated: 2021/05/03 16:14:53 by elanna           ###   ########.fr       */
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
char	*stock_frac_part_fill(char *stock_frac, char *to_add, int size_frac,
int size_add);
char	*stock_frac_part_init(char *stock_frac, char *to_add);
char	*apply_dtwo_pten(unsigned int i);
unsigned long long	convert_mant_to_frac(unsigned long long mant, short exp,
unsigned int *i);
char	*get_frac_part(unsigned long long mant, short exp);
char	*get_int_part(unsigned long long mant, short exp);
void	do_rounding(char **number, char *frac_part,
unsigned i, unsigned size);
char	*get_round_number(char *int_part, char *frac_part, int precision);
char	*get_dtoa_number(unsigned long long mant, short exp, int precision);
char	*ft_dtoa(double dbl, int precision);

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

/* Fonctions relatives aux converters */


/* Fonctions du fichier principal (ft_printf.c) */
int	ft_printf(const char *format, ...);

#endif
