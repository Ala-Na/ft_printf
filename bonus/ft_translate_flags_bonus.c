/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 14:11:04 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	add_sign(t_infos *infos_struct, char **str, char **zero_str, int *i)
{
	int		y;
	char	sign;

	sign = 0;
	y = 0;
	while (*str && (*str)[y] == ' ')
		y++;
	if (*str && (*str)[y] == '-')
		sign = '-';
	else if (*str && (*str)[y] == '+')
		sign = '+';
	if (sign == 0 && infos_struct->space == 1)
		sign = ' ';
	if (sign)
		(*zero_str)[(*i)++] = sign;
}

static void	finish_fill_zero(char **zero_str, char **str, int *i, char x)
{
	while ((*str)[*i] != 0)
	{
		(*zero_str)[*i] = (*str)[*i];
		*i += 1;
	}
	(*zero_str)[*i] = 0;
	if (x != 0)
		(*zero_str)[1] = x;
}

char	*apply_zero(t_infos *infos_struct, char **str)
{
	int		i;
	char	*zero_str;
	char	x;

	i = 0;
	x = 0;
	if (!str || !ft_strchr("diuxXefg%", infos_struct->converter)
		|| ft_strchr(*str, 'n') || (ft_strchr("diuxX%", infos_struct->converter)
			&& infos_struct->precision != -1))
		return (*str);
	zero_str = malloc(sizeof(*zero_str) * (ft_strlen(*str) + 1));
	if (!zero_str)
		return (*str);
	add_sign(infos_struct, str, &zero_str, &i);
	while (ft_strchr(" -+", (*str)[i]))
		zero_str[i++] = '0';
	if (infos_struct->minus == 0 && (*str)[i] == '0' && ((*str)[i + 1] == 'x'
		|| (*str)[i + 1] == 'X') && (*str)[i + 2] != 0)
	{
		x = (*str)[i + 1];
		(*str)[i + 1] = '0';
	}
	finish_fill_zero(&zero_str, str, &i, x);
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
