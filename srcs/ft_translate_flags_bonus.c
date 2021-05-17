/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:37:12 by elanna            #+#    #+#             */
/*   Updated: 2021/05/17 11:51:47 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
