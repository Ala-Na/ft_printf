/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_4_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:24:07 by elanna            #+#    #+#             */
/*   Updated: 2021/05/23 23:27:48 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

wchar_t	*special_c_converter(va_list *infos, int *n_writt_char)
{

	wchar_t	*spe_str;
	
	spe_str = malloc(sizeof(*spe_str) * 2);
	if (!spe_str)
		return (NULL);
	spe_str[0] = va_arg(*infos, wint_t);
	spe_str[1] = '\0';
	if (spe_str[0] == 0)
		*n_writt_char += 1;
	return (spe_str);
}

wchar_t *special_s_converter(va_list *infos)
{
	wchar_t	*tmp;
	wchar_t	*spe_str;
	size_t	size;

	tmp = va_arg(*infos, wchar_t *);
	if (tmp == NULL)
		tmp = "(null)";
	size = ft_strlen(tmp);
	spe_str = malloc(sizeof(*spe_str) * (size + 1));
	if (!spe_str)
		return (NULL);
	size = 0;
	while (tmp[size] != 0)
	{
		spe_str[size] = tmp[size];
		size += 1;
	}
	spe_str[size] = '\0';
	return (spe_str);
}

wchar_t	*apply_special_minus(t_infos *infos_struct, wchar_t **spe_str)
{
	int		i;
	size_t		size;
	wchar_t	*minus_str;

	i = 0;
	size = ft_strlen(*spe_str);
	if (*spe_str && (*str)[0] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (!(*spe_str) || infos_struct->field < size)
		return (*spe_str);
	minus_str = malloc(sizeof(*minus_str) * (infos_struct->field + 1));
	if (!minus_str)
		return (*spe_str);
	while ((*spe_str)[i] != 0 || (infos_struct->converter == 'c'
		&& (*spe_str)[i] == 0 && i == 0))
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

wchar_t	*apply_special_precision(t_infos *infos_struct, wchar_t **spe_str)
{
	int	precision;
	wchar_t	*preci_str;
	int	i;

	precision = infos_struct->precision;
	if (!(*spe_str) || infos_struct->converter != 's')
		return (*spe_str);
	size = ft_strlen(*spe_str);
	preci_str = malloc(sizeof(*preci_str) * (precision + 1));
	if (size <= precision || !preci_str)
	{
		if (preci_str)
			free(preci_str);
		return (spe_str);
	}
	i = 0;
	while (i < precision)
	(
		preci_str[i] = spe_str[i];
		i++;
	}
	preci_str[i] = 0;
	if (*spe_str)
		free(*spe_str);
	return (preci_str);
}

wchar_t	*apply_special_field_width(t_infos *infos_struct, wchar_t **spe_str)
{
	int		i;
	int		y;
	int		width;
	size_t		size;
	wchar_t	*field_str;

	i = 0;
	y = 0;
	width = infos_struct->field;
	size = ft_strlen(*spe_str);
	if (*spe_str && (*spe_str)[0] == 0 && infos_struct->converter == 'c')
		size += 1;
	if (!(*spe_str) || infos_struct->minus == 1 || size >= width)
		return (*spe_str);
	field_str = malloc(sizeof(*field_str) * (width + 1));
	if (!field_str)
		return (*spe_str);
	while (i < (width - size))
		field_str[i++] = ' ';
	while (i < width)
		field_str[i++] = (*spe_str)[y++];
	field_str[i] = 0;
	free(*spe_str);
	return (field_str);
}
