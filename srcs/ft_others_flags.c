/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 23:41:25 by elanna            #+#    #+#             */
/*   Updated: 2021/05/14 16:08:24 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_zero(t_infos *infos_struct, char **str)
{
	char	conv;
	int		i;
	char	*zero_str;

	i = 0;
	conv = infos_struct->converter;
	if (!(ft_strchr("diuxXefGg", conv)))
		return (*str);
	if (!(zero_str = malloc(sizeof(*zero_str) * (ft_strlen(*str) + 1))))
		return (*str);
	while ((*str)[i] == ' ')
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
	int		format_size;
	char	*minus_str;

	i = 0;
	format_size = infos_struct->format_size;
	if (format_size < (int)ft_strlen(*str))
		return (*str);
	if (!(minus_str = malloc(sizeof(*minus_str) * (format_size + 1))))
		return (*str);
	while ((*str)[i] != 0)
	{
		minus_str[i] = (*str)[i];
		i++;
	}
	while (i < format_size)
	{
		minus_str[i] = ' ';
		i++;
	}
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
