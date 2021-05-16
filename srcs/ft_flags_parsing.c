/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:55:51 by elanna            #+#    #+#             */
/*   Updated: 2021/05/16 21:44:19 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length_double(char length_code, t_infos *infos_struct, char **s)
{
	infos_struct->length = length_code;
	infos_struct->format_size += 1;
	(*s)++;
}

char	*parse_length(t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	if (*s == 'l')
	{
		s++;
		if (*s == 'l')
			parse_length_double(3, infos_struct, &s);
		else
			infos_struct->length = 1;
	}
	else if (*s == 'h')
	{
		s++;
		if (*s == 'h')
			parse_length_double(4, infos_struct, &s);
		else
			infos_struct->length = 2;
	}
	infos_struct->format_size += 1;
	return (s);
}

char	*parse_precision(va_list *infos, t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	stock_infos_parsed(infos_struct, *s);
	s++;
	infos_struct->precision = 0;
	if (*s == '*')
	{
		infos_struct->precision = (int)va_arg(*infos, int);
		stock_infos_parsed(infos_struct, *s);
		s++;
	}
	else
	{
		while (ft_isdigit(*s))
		{
			infos_struct->precision *= 10;
			infos_struct->precision += *s - '0';
			stock_infos_parsed(infos_struct, *s);
			s++;
		}
	}
	if (infos_struct->precision < 0)
		infos_struct->precision = -1;
	else
		infos_struct->zero = 0;
	return (s);
}

char	*parse_field_width(va_list *infos, t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	if (*s == '*')
	{
		infos_struct->field = (int)va_arg(*infos, int);
		stock_infos_parsed(infos_struct, *s);
		if (infos_struct->field < 0)
		{
			infos_struct->field *= -1;
			infos_struct->minus = 1;
		}
		s++;
	}
	else
	{
		while (ft_isdigit(*s))
		{
			if (infos_struct->field == -1)
				infos_struct->field = 0;
			infos_struct->field *= 10;
			infos_struct->field += *s - '0';
			stock_infos_parsed(infos_struct, *s);
			s++;
		}
	}
	return (s);
}

char	*parse_flags(t_infos *infos_struct, char *str)
{
	char	*s;

	s = str;
	if (*s == '-')
	{
		infos_struct->minus = 1;
		infos_struct->zero = 0;
	}
	else if (*s == '0' && infos_struct->minus == 0)
		infos_struct->zero = 1;
	else if (*s == '#')
		infos_struct->hash = 1;
	else if (*s == '+')
	{
		infos_struct->space = 0;
		infos_struct->plus = 1;
	}
	else if (*s == ' ' && infos_struct->plus == 0)
		infos_struct->space = 1;
	stock_infos_parsed(infos_struct, *s);
	s++;
	return (s);
}
