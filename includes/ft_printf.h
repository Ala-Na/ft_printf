/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:48 by elanna            #+#    #+#             */
/*   Updated: 2021/05/21 21:53:59 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "libft_bonus.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

/*
** Useful for tests :
*/
# include <stdio.h>
# include <math.h>
# include <limits.h>

/*
** Global variables, useful for parsing.
*/
extern char		*g_flags;
extern char		*g_conversion_specifier;

/*
** Structure useful to stock infos about format.
*/
typedef struct	s_infos
{
	char	valid;
	char	*invalid;
	char	minus;
	char	zero;
	char	hash;
	char	plus;
	char	space;
	int		field;
	int		precision;
	char	length;
	char	converter;
	int		format_size;
}				t_infos;

/*
** Function initializing the structure containing infos about format
*/
t_infos			*init_infos_struct(void);

/*
** Functions for parsing infos about format
*/
void			stock_infos_parsed(t_infos *infos_struct, char c);
char			*parse_converter(t_infos *infos_struct, char *str);
t_infos			*parse_format(const char **format, va_list *infos);

char			*parse_precision(va_list *infos,
t_infos *infos_struct, char *str);
char			*parse_field_width(va_list *infos,
t_infos *infos_struct, char *str);
char			*parse_flags(t_infos *infos_struct, char *str);

/*
** Functions to translate format into a string
*/
char			*ft_translate_flags(t_infos *infos_struct, char **str);
char			*translate_converter(t_infos *infos_struct,
va_list *infos, int *n_writt_char);
char			*ft_translate_format(t_infos *infos_struct,
va_list *infos, int *n_writt_char);

char			*c_converter(va_list *infos, int *n_writt_char);
char			*s_converter(va_list *infos);
char			*percent_converter(void);
char			*p_converter(va_list *infos);

char			*i_d_converter(va_list *infos, char length,
int precision);
char			*u_converter(va_list *infos, char length, int precision);
char			*x_converter(va_list *infos, char length, int precision);
char			*grand_x_converter(va_list *infos, char length, int precision);

char			*apply_zero(t_infos *infos_struct, char **str);
char			*apply_minus(t_infos *infos_struct, char **str);

char			*apply_field_width(t_infos *infos_struct, char **str);
void			apply_precision_on_str(char **preci_str, char *str,
int precision);
void			apply_precision_on_number(char **preci_str, char *str,
int precision);
char			*apply_precision(t_infos *infos_struct, char **str);

/*
** Functions of main file
*/
char			*get_infos(const char **format, va_list *infos,
int *n_writt_char, char *is_char);
int				ft_printf(const char *format, ...);

#endif
