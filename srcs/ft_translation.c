/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:12:19 by elanna            #+#    #+#             */
/*   Updated: 2021/05/14 17:59:13 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*translate_flags(t_infos *infos_struct, char **str)
{
	char	*new;

	new = *str;
	if (infos_struct->converter == 'n')
		return (*str);
	if (infos_struct->hash == 1)
		new = apply_hash(infos_struct, str);
	if (infos_struct->precision != -1)
		new = apply_precision(infos_struct, str);
	if (infos_struct->minus == 1)
		new = apply_minus(infos_struct, str);
	else if (infos_struct->field != -1)
		new = apply_field_width(infos_struct, str);
	if (infos_struct->zero == 1)
		new = apply_zero(infos_struct, str);
	if (infos_struct->plus == 1)
		new = apply_plus(infos_struct, str);
	else if (infos_struct->space == 1)
		new = apply_space(infos_struct, str);
	return (new);
}

void	translate_converter_2(char **str, t_infos *infos_struct, va_list *infos,
int n_writt_char)
{
	char conv;

	conv = infos_struct->converter;
	if (conv == 'p')
		*str = p_converter(infos);
	else if (conv == 'f')
		*str = f_converter(infos, infos_struct->precision);
	else if (conv == 'e')
		*str = e_converter(infos, infos_struct->precision);
	else if (conv == 'g')
		*str = g_converter(infos, infos_struct->precision);
	else if (conv == 'n')
		*str = n_converter(infos, n_writt_char);
}

char	*translate_converter_1(t_infos *infos_struct, va_list *infos,
int n_writt_char)
{
	char	conv;
	char	*str;

	conv = infos_struct->converter;
	if (conv == 'c')
		str = c_converter(infos);
	else if (conv == 's')
		str = s_converter(infos);
	else if (conv == 'd' || conv == 'i')
		str = i_d_converter(infos, infos_struct->length,
		infos_struct->precision);
	else if (conv == '%')
		str = percent_converter();
	else if (conv == 'u')
		str = u_converter(infos, infos_struct->length);
	else if (conv == 'x')
		str = x_converter(infos, infos_struct->length,
		infos_struct->hash);
	else if (conv == 'X')
		str = grand_x_converter(infos, infos_struct->length,
		infos_struct->hash);
	else
		translate_converter_2(&str, infos_struct, infos, n_writt_char);
	return (str);
}

char	*ft_translate_format(t_infos *infos_struct, va_list *infos,
int n_writt_char)
{
	char *str;

	if (infos_struct->valid == 0)
		return (infos_struct->invalid);
	str = translate_converter_1(infos_struct, infos, n_writt_char);
	str = translate_flags(infos_struct, &str);
	return (str);
}
