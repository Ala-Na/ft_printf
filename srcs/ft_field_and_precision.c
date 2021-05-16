/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_and_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:31:23 by elanna            #+#    #+#             */
/*   Updated: 2021/05/16 23:04:32 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_field_width(t_infos *infos_struct, char **str)
{
	int		i;
	int		y;
	int		width;
	int		size;
	char	*field_str;

	i = 0;
	y = 0;
	width = infos_struct->field;
	size = (int)ft_strlen(*str);
	if ((*str)[0] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (infos_struct->minus == 1 || size >= width)
		return (*str);
	if (!(field_str = malloc(sizeof(*field_str) * (width + 1))))
		return (*str);
	while (i < (width - size))
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
	int	i;
	int	y;
	int	size;
	int	sign;

	size = 0;
	i = 0;
	y = 0;
	if (str[i] == '-')
		i++;
	sign = i;
	while (ft_ishexa(str[i++]))
		size++;
	if (size >= precision ||
		!(*preci_str = malloc(sizeof(**preci_str) * (precision + 1 + sign))))
	{
		(*preci_str) = ft_strdup(str);
		return ;
	}
	i = 0;
	if (str[y] == '-')
		(*preci_str)[i++] = str[y++];
	while (i < (precision + sign - size))
		(*preci_str)[i++] = '0';
	while (str[y] != 0 && i < (precision + sign))
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
