/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:38:34 by elanna            #+#    #+#             */
/*   Updated: 2021/06/18 00:23:39 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	translate_converter_bonus(char **str, t_infos *infos_struct,
va_list *infos, int *n_writt_char)
{
	char	conv;

	conv = infos_struct->converter;
	if (conv == 'f')
		*str = f_converter(infos, infos_struct->precision);
	else if (conv == 'e')
		*str = e_converter(infos, infos_struct->precision);
	else if (conv == 'g')
		*str = g_converter(infos, infos_struct->precision);
	else if (conv == 'n')
		*str = n_converter(infos, infos_struct->length, *n_writt_char);
}

char	*translate_flags(t_infos *infos_struct, char **str)
{
	char	*new;

	new = *str;
	if (infos_struct->converter == 'n')
		return (new);
	if (infos_struct->precision != -1)
		new = apply_precision(infos_struct, &new);
	if (infos_struct->hash == 1)
		new = apply_hash(infos_struct, &new);
	if (infos_struct->plus == 1)
		new = apply_plus(infos_struct, &new);
	else if (infos_struct->space == 1)
		new = apply_space(infos_struct, &new);
	if (infos_struct->minus == 1)
		new = apply_minus(infos_struct, &new);
	else if (infos_struct->field != -1)
		new = apply_field_width(infos_struct, &new);
	if (infos_struct->zero == 1 && infos_struct->minus == 0)
		new = apply_zero(infos_struct, &new);
	return (new);
}

char	*translate_converter(t_infos *infos_struct, va_list *infos,
int *n_writt_char)
{
	char	conv;
	char	*str;

	conv = infos_struct->converter;
	str = NULL;
	if (conv == 'c' && infos_struct->length != 1)
		str = c_converter(infos, n_writt_char);
	else if (conv == 's')
		str = s_converter(infos);
	else if (conv == 'd' || conv == 'i')
		str = i_d_converter(infos, infos_struct->length,
				infos_struct->precision);
	else if (conv == '%')
		str = percent_converter();
	else if (conv == 'u')
		str = u_converter(infos, infos_struct->length, infos_struct->precision);
	else if (conv == 'x')
		str = x_converter(infos, infos_struct->length, infos_struct->precision);
	else if (conv == 'X')
		str = grand_x_converter(infos, infos_struct->length,
				infos_struct->precision);
	else if (conv == 'p')
		str = p_converter(infos, infos_struct->precision);
	return (str);
}

char	*ft_translate_format(t_infos *infos_struct, va_list *infos,
int *n_writt_char)
{
	char	*str;

	if (infos_struct->valid == 0)
		return (infos_struct->invalid);
	str = translate_converter(infos_struct, infos, n_writt_char);
	if (str == NULL)
		translate_converter_bonus(&str, infos_struct, infos, n_writt_char);
	if (str != NULL)
		str = translate_flags(infos_struct, &str);
	return (str);
}
