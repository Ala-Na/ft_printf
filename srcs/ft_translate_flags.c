/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/05/19 22:00:44 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_zero(t_infos *infos_struct, char **str)
{
	char	conv;
	int		i;
	char	*zero_str;
	char	*sign;

	i = 0;
	conv = infos_struct->converter;
	if (!(ft_strchr("diuxXefg", conv)) || ft_strchr(*str, 'n'))
		return (*str);
	if (!(zero_str = malloc(sizeof(*zero_str) * (ft_strlen(*str) + 1))))
		return (*str);
	if ((conv != 'e' && conv != 'g') && (((sign = ft_strchr(*str, '+'))
		|| (sign = ft_strchr(*str, '-')))))
		zero_str[i++] = sign[0];
	else if ((conv == 'e' || conv == 'g') && ft_strchr(*str, '-') != NULL)
		zero_str[i++] = '-';
	else if ((conv == 'e' || conv == 'g') && infos_struct->plus == 1)
		zero_str[i++] = '+';
	else if (infos_struct->space == 1)
		zero_str[i++] = ' ';
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
	while ((*str)[i] != 0)
	{
		minus_str[i] = (*str)[i];
		i++;
	}
	while (i < field_size)
	{
		minus_str[i] = ' ';
		i++;
	}
	if ((*str)[0] == 0 && infos_struct->converter == 'c')
		--i;
	minus_str[i] = 0;
	free(*str);
	return (minus_str);
}
