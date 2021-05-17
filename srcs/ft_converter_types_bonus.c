/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:47:52 by elanna            #+#    #+#             */
/*   Updated: 2021/05/17 11:47:21 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*f_converter(va_list *infos, int precision)
{
	char	*str;
	double	dbl;

	dbl = (double)va_arg(*infos, double);
	if (precision == -1)
		precision = 6;
	str = ft_dtoa(dbl, precision, 0);
	return (str);
}

char	*e_converter(va_list *infos, int precision)
{
	char	*str;
	double	dbl;

	dbl = (double)va_arg(*infos, double);
	if (precision == -1)
		precision = 6;
	str = ft_dtoa(dbl, precision, 1);
	return (str);
}

char	*g_converter(va_list *infos, int precision)
{
	char	*str;
	double	dbl;

	dbl = (double)va_arg(*infos, double);
	if (precision == -1)
		precision = 6;
	str = ft_dtoa_shortest_rep(dbl, precision);
	return (str);
}

char	*n_converter(va_list *infos, int n_writt_char)
{
	int *ptr;

	ptr = (int*)va_arg(*infos, int*);
	*ptr = n_writt_char;
	return (NULL);
}
