/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:47:52 by elanna            #+#    #+#             */
/*   Updated: 2021/05/14 14:48:08 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
