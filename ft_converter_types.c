/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:15:07 by elanna            #+#    #+#             */
/*   Updated: 2021/04/15 17:02:58 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "ft_printf.h"

/* Est-ce que je malloc tout où est-ce que je tente des string const ?*/

char	*c_converter(va_list *infos)
{
	char *str[2];

	str[0] = (char)va_arg(*infos, char);
	str[1] = '\0';
	return (str);
}

char	*s_converter(va_list *infos)
{
	char *str;

	str = (char*)va_arg(*infos, char*);
	return (str);
}

char	*i_d_converter(va_list *infos, char length)
{
	char	*str;
	long long	integer;
	
	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0);
			integer = (long long)va_list(*infos, int);
		else if (length == 2)
			integer = (long long)va_list(*infos, short);
		else
			integer = (long long)va_list(*infos, char);
		str = ft_itoa((int)integer);
	}
	else
	{
		if (length == 1)
			integer = (long long)va_list(*infos, long);
		else
			integer = (long long)va_list(*infos, long long);
		str = ft_llitoa((long long)integer);
	}
	return (str);
}

char	*percent_converter()
{
	char *str;

	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char	*u_converter(va_list *infos, char length)
{
	char *str;
	unsigned long long un_integer;
	
	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0);
			un_integer = (unsigned long long)va_list(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned long long)va_list(*infos, unsigned short);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned char);
		str = ft_uitoa((unsigned int)un_integer);
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long long)va_list(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned long long);
		str = ft_ullitoa((unsigned long long)un_integer);
	}
	return (str);
}

char	*x_converter(va_list *infos, char length)
{
	char		*str;
	unsigned int	un_integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0);
			un_integer = (unsigned long long)va_list(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned long long)va_list(*infos, unsigned short);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned char);
		str = ft_uitobase((unsigned int)un_integer, "0123456789abcdef");
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long long)va_list(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned long long);
		str = ft_ullitobase((unsigned long long)un_integer, "0123456789abcdef");
	}
	return (str);
}

char	*X_converter(va_list *infos, char length)
{
	char		*str;
	unsigned int	un_integer;

	if (length == 0 || length == 2 || length == 4)
	{
		if (length == 0);
			un_integer = (unsigned long long)va_list(*infos, unsigned int);
		else if (length == 2)
			un_integer = (unsigned long long)va_list(*infos, unsigned short);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned char);
		str = ft_uitobase((unsigned int)un_integer, "0123456789ABCDEF");
	}
	else
	{
		if (length == 1)
			un_integer = (unsigned long long)va_list(*infos, unsigned long);
		else
			un_integer = (unsigned long long)va_list(*infos, unsigned long long);
		str = ft_ullitobase((unsigned long long)un_integer, "0123456789ABCDEF");
	}
	return (str);
}

char	*p_converter(va_list *infos)
{
	char	*str;
	void	*addr;

	addr = (void*)va_list(*infos, void*);
	str = ft_hexaddr(addr);
	return (str);
}

char	*f_converter(va_list *infos, t_infos *infos_struct)
{
	char	*str;
	double	dbl;

	dbl = (double)va_list(*infos, double);
	str = ft_dtoa(dbl, infos_struct->precision);
	return (str);
}
