/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parsing_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:55:51 by elanna            #+#    #+#             */
/*   Updated: 2021/05/19 15:48:01 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	if (ft_strchr("diuxX", infos_struct->converter)[0] != 0 && infos_struct->precision > 0)
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
	else
		parse_bonus_flags(infos_struct, s);
	stock_infos_parsed(infos_struct, *s);
	s++;
	return (s);
}
