/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_3_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:47:52 by elanna            #+#    #+#             */
/*   Updated: 2021/05/23 21:09:50 by elanna           ###   ########.fr       */
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
	if ((ft_strncmp("9223372036854775808", str, 19)) == 0
		&& ft_strlen(str) > 20)
		str[20] = '0';
	else if ((ft_strncmp("-9223372036854775808", str, 20)) == 0
		&& ft_strlen(str) > 21)
		str[21] = '0';
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

char	*n_converter(va_list *infos, char length, int n_writt_char)
{
	if (length == 0)
		va_arg(*infos, int *)[0] = n_writt_char;
	else if (length == 1)
		va_arg(*infos, long int *)[0] = n_writt_char;
	else if (length == 2)
		va_arg(*infos, short int *)[0] = n_writt_char;
	else if (length == 3)
		va_arg(*infos, long long int *)[0] = n_writt_char;
	else if (length == 4)
		va_arg(*infos, char *)[0] = n_writt_char;
	return (NULL);
}
