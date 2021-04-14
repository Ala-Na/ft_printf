/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:48 by elanna            #+#    #+#             */
/*   Updated: 2021/04/14 11:52:10 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// UNIQUEMENT POUR LES TESTS !!! A SUPPRIMER !!!
# include <stdio.h>

//Variables globales pour rendre aisée la comparaison, définies dans ft_parsing.c
extern char	*FLAGS;
extern char	*CONVERSION_SPECIFIER;

//Structure nécessaire pour stocker les informations
//relatives au format
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

//Fonctions issues de libft (ft_libft_needed.c)
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int	ft_isdigit(int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

//Fonctions pouvant être ajoutées à libft (ft_newft_libft.c)
char	*ft_uitoa(unsigned int n);

//Fonctions relatives à la structure (ft_struct.c)
t_infos	*init_infos_struct();

//Fonctions relatives au parsing (ft_parsing.c)
t_infos	*parse_format(const char **format, va_list *infos);
char	*parse_flags(t_infos *infos_struct, char *str);
char	*parse_field_width(va_list *infos, t_infos *infos_struct, char *str);
void	stock_infos_read(t_infos *infos_struct, char c);
char	*parse_precision(t_infos *infos_struct, char *str);
char	*parse_length(t_infos *infos_struct, char *str);
char	*parse_converter(t_infos *infos_struct, char *str);
void	stock_infos_parsed(t_infos *infos_struct, char c);

//Fonctions relatives a la translation (ft_translation.c)
char	*ft_translate_format(t_infos *infos_struct, va_list *infos);

//Fonctions relatives aux converters


//Fonctions du fichier principal (ft_printf.c)
int	ft_printf(const char *format, ...);

#endif
