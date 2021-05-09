/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:15:07 by elanna            #+#    #+#             */
/*   Updated: 2021/05/09 17:25:25 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "ft_printf.h"

char	*c_converter(va_list *infos)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * 2)))
		return (NULL);
	str[0] = (char)va_arg(*infos, char);
	str[1] = '\0';
	return (str);
}

char	*s_converter(va_list *infos)
{
	char	*tmp;
	char	*str;
	int	size;

	tmp = (char*)va_arg(*infos, char*);
	size = ft_strlen(tmp);
	if(!(str = malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	size = 0;
	while (tmp[size] != 0)
		str[size] = tmp[size++];
	str[size] = '\0';
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
p	char	*str;

	if (!(str = malloc(sizeof(*str) * 2)))
		return (NULL);
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

char	*x_converter(va_list *infos, char length, char hash)
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
	if (hash)
		str = add_chars_to_mall_str(str, "0x", 'f');
	return (str);
}

char	*X_converter(va_list *infos, char length, char hash)
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
	if (hash)
		str = add_chars_to_mall_str(str, "0X", 'f');
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
	str = ft_dtoa(dbl, infos_struct->precision, 0);
	return (str);
}

char	*e_converter(va_list *infos, t_infos *infos_struct)
{
	char	*str;
	double	dbl;

	dbl = (double)va_list(*infos, double);
	str = ft_dtoa(dbl, infos_struct->precision, 1);
	return (str);
}

char	*g_converter(va_list *infos, t_infos *infos_struct)
{
	char	*str;
	double	dbl;

	dbl = (double)va_list(*infos, double);
	str = ft_dtoa_shortest_rep(dbl, infos_struct->precision, infos_struct->hash);
	return (str);
}

char	*n_converter(char *str)
{
	int len;

	len = ft_strlen(str);
	return (ft_itoa(len));
}
