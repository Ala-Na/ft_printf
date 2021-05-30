/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/05/29 23:30:39 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	find_sign(t_infos *infos_struct, char **str)
{
	char	*sign_str;
	int		i;

	if (!(ft_strchr("eg", infos_struct->converter)))
	{
		sign_str = ft_strchr(*str, '+');
		if (sign_str)
			return ('+');
		sign_str = ft_strchr(*str, '-');
		if (sign_str)
			return ('-');
	}
	else
	{
		i = 0;
		while (*str && (*str)[i] == ' ')
			i++;
		if (*str && (*str)[i] == '-')
			return ('-');
		else if (*str && (*str)[i] == '+')
			return ('+');
	}
	if (infos_struct->space == 1)
		return (' ');
	return (0);
}

char	*apply_zero(t_infos *infos_struct, char **str)
{
	int		i;
	char	*zero_str;
	char	sign;

	i = 0;
	if (!str || !ft_strchr("diuxXefg%", infos_struct->converter)
		|| ft_strchr(*str, 'n') || (ft_strchr("diuxX%", infos_struct->converter)
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
	int		size;
	char	*minus_str;

	i = 0;
	size = ft_strlen(*str);
	if (*str && (*str)[0] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (!(*str) || infos_struct->field < size)
		return (*str);
	minus_str = malloc(sizeof(*minus_str) * (infos_struct->field + 1));
	if (!minus_str)
		return (*str);
	while ((*str)[i] != 0 || (infos_struct->converter == 'c'
		&& (*str)[i] == 0 && i == 0))
	{
		minus_str[i] = (*str)[i];
		i++;
	}
	while (i < infos_struct->field)
		minus_str[i++] = ' ';
	minus_str[i] = 0;
	free(*str);
	return (minus_str);
}
