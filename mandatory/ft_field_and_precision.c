/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_and_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:31:23 by elanna            #+#    #+#             */
/*   Updated: 2021/05/26 15:15:52 by anadege          ###   ########.fr       */
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
	if (*str && (*str)[i] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (!str || infos_struct->minus == 1 || size >= width)
		return (*str);
	field_str = malloc(sizeof(*field_str) * (width + 1));
	if (!field_str)
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
	*preci_str = malloc(sizeof(**preci_str) * (precision + 1));
	if (size <= precision || !(*preci_str))
	{
		if (*preci_str)
			free(*preci_str);
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

static void	fill_precision_number(char **preci_str, char *str,
int precision, int size)
{
	int	i;
	int	y;
	int	sign;

	i = 0;
	y = 0;
	sign = 0;
	if (str[y] == '-')
	{
		(*preci_str)[i++] = str[y++];
		sign++;
	}
	while (i < (precision + sign - size))
		(*preci_str)[i++] = '0';
	while (str[y] != 0 && i < (precision + sign))
		(*preci_str)[i++] = str[y++];
	(*preci_str)[i] = 0;
}

void	apply_precision_on_number(char **preci_str, char *str, int precision)
{
	int	i;
	int	size;
	int	sign;

	size = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	sign = i;
	while (ft_ishexa(str[i++]))
		size++;
	*preci_str = malloc(sizeof(**preci_str) * (precision + 1 + sign));
	if (size >= precision || !(*preci_str))
	{
		if (*preci_str)
			free(*preci_str);
		(*preci_str) = ft_strdup(str);
		return ;
	}
	fill_precision_number(preci_str, str, precision, size);
}

char	*apply_precision(t_infos *infos_struct, char **str)
{
	int		precision;
	char	conv;
	char	*preci_str;

	precision = infos_struct->precision;
	conv = infos_struct->converter;
	if (!str || !(ft_strchr("diuxXs", conv)))
		return (*str);
	else if (conv == 's')
		apply_precision_on_str(&preci_str, *str, precision);
	else
		apply_precision_on_number(&preci_str, *str, precision);
	if (*str)
		free(*str);
	return (preci_str);
}
