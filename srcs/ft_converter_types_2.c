/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:15:07 by elanna            #+#    #+#             */
/*   Updated: 2021/05/19 22:27:05 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	empty_case(char **str)
{
	if (*str)
		free(*str);
	*str = ft_strdup("");
}

char		*i_d_converter(va_list *infos, char length, int precision)
{
	char		*str;
	long long	integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0)
			integer = (int)va_arg(*infos, int);
		else if (length == 2)
			integer = (short)va_arg(*infos, int);
		else
			integer = (char)va_arg(*infos, int);
		str = ft_itoa((int)integer);
	}
	else
	{
		if (length == 1)
			integer = (long long)va_arg(*infos, long);
		else
			integer = (long long)va_arg(*infos, long long);
		str = ft_llitoa(integer);
	}
	if (precision == 0 && str[0] == '0' && str[1] == 0)
		empty_case(&str);
	return (str);
}

char		*u_converter(va_list *infos, char length, int precision)
{
	char				*str;
	unsigned long long	un_integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0)
			un_integer = (unsigned int)va_arg(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned short)va_arg(*infos, unsigned int);
		else
			un_integer = (unsigned char)va_arg(*infos, unsigned int);
		str = ft_uitoa((unsigned int)un_integer);
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long long)va_arg(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_arg(*infos, unsigned long long);
		str = ft_ullitoa((unsigned long long)un_integer);
	}
	if (precision == 0 && str[0] == '0' && str[1] == 0)
		empty_case(&str);
	return (str);
}

char		*x_converter(va_list *infos, char length, int precision)
{
	char				*str;
	unsigned long long	un_integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0)
			un_integer = (unsigned int)va_arg(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned short)va_arg(*infos, unsigned int);
		else
			un_integer = (unsigned char)va_arg(*infos, unsigned int);
		str = ft_uitobase((unsigned int)un_integer, "0123456789abcdef");
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long)va_arg(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_arg(*infos, unsigned long long);
		str = ft_ullitobase(un_integer, "0123456789abcdef");
	}
	if (precision == 0 && str[0] == '0' && str[1] == 0)
		empty_case(&str);
	return (str);
}

char		*grand_x_converter(va_list *infos, char length, int precision)
{
	char				*str;
	unsigned long long	un_integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0)
			un_integer = (unsigned int)va_arg(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned short)va_arg(*infos, unsigned int);
		else
			un_integer = (unsigned char)va_arg(*infos, unsigned int);
		str = ft_uitobase((unsigned int)un_integer, "0123456789ABCDEF");
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long)va_arg(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_arg(*infos, unsigned long long);
		str = ft_ullitobase(un_integer, "0123456789ABCDEF");
	}
	if (precision == 0 && str[0] == '0' && str[1] == 0)
		empty_case(&str);
	return (str);
}
