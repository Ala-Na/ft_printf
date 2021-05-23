/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/05/23 15:31:41 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	find_sign(t_infos *infos_struct, char **str)
{
	char	*sign_str;
	char	conv;
	int	i;

	conv = infos_struct->converter;
	if (conv != 'e' && conv != 'g')
	{
		sign_str = ft_strchr(*str, '+');
		if (sign_str)
			return ('+');
		sign_str = ft_strchr(*str, '-');
		if (sign_str)
			return ('-');
	}
	else if (infos_struct->space == 1)
		return (' ');
	else if (conv == 'e' || conv == 'g')
	{
		i = 0;
		while ((*str)[i] == ' ')
			i++;
		if ((*str)[i] == '-')
			return ('-');
		else if ((*str)[i] == '+')
			return ('+');
	}
	return (0);
	
}

char	*apply_zero(t_infos *infos_struct, char **str)
{
	int		i;
	char	*zero_str;
	char	sign;

	i = 0;
	if (!(ft_strchr("diuxXefg", infos_struct->converter))
		|| ft_strchr(*str, 'n')
		|| (ft_strchr("diuxX", infos_struct->converter)
		&& infos_struct->precision != -1))
		return (*str);
	zero_str = malloc(sizeof(*zero_str) * (ft_strlen(*str) + 1));
	if (!zero_str)
		return (*str);
	sign = find_sign(infos_struct, str);
	if (sign != 0)
		zero_str[i++] = sign;
	while (ft_strchr(" -+", (*str)[i]))
		zero_str[i++] = '0';
	while ((*str)[i] != 0)
	{
		zero_str[i] = (*str)[i];
		i++;
	}
	zero_str[i] = 0;
	free(*str);
	return (zero_str);
}

char	*apply_minus(t_infos *infos_struct, char **str)
{
	int		i;
	int		field_size;
	int		size;
	char	*minus_str;

	i = 0;
	field_size = infos_struct->field;
	size = ft_strlen(*str);
	if ((*str)[0] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (field_size < size)
		return (*str);
	if (!(minus_str = malloc(sizeof(*minus_str) * (field_size + 1))))
		return (*str);
	while ((*str)[i] != 0 || (infos_struct->converter == 'c'
		&& (*str)[i] == 0 && i == 0))
	{
		minus_str[i] = (*str)[i];
		i++;
	}
	while (i < field_size)
		minus_str[i++] = ' ';
	minus_str[i] = 0;
	free(*str);
	return (minus_str);
}
