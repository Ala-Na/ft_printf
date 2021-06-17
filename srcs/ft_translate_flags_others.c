/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags_others.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:37:12 by elanna            #+#    #+#             */
/*   Updated: 2021/06/18 00:00:08 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_space(t_infos *infos_struct, char **str)
{
	int		i;
	int		y;
	char	*space_str;

	i = 0;
	if (!(ft_strchr("diuxXfge", infos_struct->converter))
		|| ft_strchr(*str, 'a'))
		return (*str);
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return (*str);
	space_str = malloc(sizeof(*space_str) + (ft_strlen(*str) + 2));
	if (!space_str)
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
	char	*plus_str;

	i = 0;
	if (!(ft_strchr("diuxXfge", infos_struct->converter))
		|| ft_strchr(*str, 'a'))
		return (*str);
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return (*str);
	plus_str = malloc(sizeof(*plus_str) + (ft_strlen(*str) + 2));
	if (!plus_str)
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
