/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_and_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:31:23 by elanna            #+#    #+#             */
/*   Updated: 2021/05/14 21:51:28 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_field_width(t_infos *infos_struct, char **str)
{
	int		i;
	int		y;
	int		width;
	char	*field_str;

	i = 0;
	y = 0;
	width = infos_struct->field;
	if (infos_struct->minus == 1 || (int)ft_strlen(*str) >= width)
		return (*str);
	if (!(field_str = malloc(sizeof(*field_str) * (width + 1))))
		return (*str);
	while (i < (width - (int)ft_strlen(*str)))
		field_str[i++] = ' ';
	while (i < width)
		field_str[i++] = (*str)[y++];
	field_str[i] = 0;
	free(*str);
	return (field_str);
}

void	apply_precision_on_str(char **preci_str, char *str, int precision)
{
	int	i;
	int	size;

	size = ft_strlen(str);
	if (size <= precision ||
		!(*preci_str = malloc(sizeof(**preci_str) * (precision + 1))))
	{
		(*preci_str) = ft_strdup(str);
		return ;
	}
	i = 0;
	while (i < precision)
	{
		(*preci_str)[i] = str[i];
		i++;
	}
	(*preci_str)[i] = 0;
}

void	apply_precision_on_number(char **preci_str, char *str, int precision)
{
	int i;
	int y;
	int size;

	size = 0;
	i = 0;
	y = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i++] <= '9') ||
		(str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
		size++;
	if (size >= precision ||
		!(*preci_str = malloc(sizeof(**preci_str) * (precision + 1))))
	{
		(*preci_str) = ft_strdup(str);
		return ;
	}
	i = 0;
	while (i < precision - size)
		(*preci_str)[i++] = '0';
	while (str[y] != 0)
		(*preci_str)[i++] = str[y++];
	(*preci_str)[i] = 0;
}

char	*apply_precision(t_infos *infos_struct, char **str)
{
	int		precision;
	char	conv;
	char	*preci_str;

	precision = infos_struct->precision;
	conv = infos_struct->converter;
	if (!(ft_strchr("diuxXs", conv)))
		return (*str);
	else if (conv == 's')
		apply_precision_on_str(&preci_str, *str, precision);
	else
		apply_precision_on_number(&preci_str, *str, precision);
	free(*str);
	return (preci_str);
}
