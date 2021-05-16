/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/05/16 23:04:08 by elanna           ###   ########.fr       */
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
	if (!(ft_strchr("diuxXefGg", conv)))
		return (*str);
	if (!(zero_str = malloc(sizeof(*zero_str) * (ft_strlen(*str) + 1))))
		return (*str);
	if ((sign = ft_strchr(*str, '+')) || (sign = ft_strchr(*str, '-')))
		zero_str[i++] = sign[0];
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

char	*apply_space(t_infos *infos_struct, char **str)
{
	int		i;
	int		y;
	char	conv;
	char	*space_str;

	i = 0;
	conv = infos_struct->converter;
	if (!(ft_strchr("diuxXfge", conv)))
		return (*str);
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return (*str);
	if (!(space_str = malloc(sizeof(*space_str) + (ft_strlen(*str) + 2))))
		return (*str);
	i = 0;
	y = 0;
	while ((*str)[i] == ' ')
		space_str[y++] = (*str)[i++];
	space_str[y++] = ' ';
	while ((*str)[i] != 0)
		space_str[y++] = (*str)[i++];
	space_str[y] = 0;
	free(*str);
	return (space_str);
}

char	*apply_plus(t_infos *infos_struct, char **str)
{
	int		i;
	int		y;
	char	conv;
	char	*plus_str;

	i = 0;
	conv = infos_struct->converter;
	if (!(ft_strchr("diuxXfge", conv)))
		return (*str);
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return (*str);
	if (!(plus_str = malloc(sizeof(*plus_str) + (ft_strlen(*str) + 2))))
		return (*str);
	i = 0;
	y = 0;
	while ((*str)[i] == ' ')
		plus_str[y++] = (*str)[i++];
	plus_str[y++] = '+';
	while ((*str)[i] != 0)
		plus_str[y++] = (*str)[i++];
	plus_str[y] = 0;
	free(*str);
	return (plus_str);
}
