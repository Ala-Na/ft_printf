/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:12:19 by elanna            #+#    #+#             */
/*   Updated: 2021/06/02 11:40:36 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*translate_flags(t_infos *infos_struct, char **str)
{
	char	*new;

	new = *str;
	if (infos_struct->converter == 'n' || infos_struct->converter == '%')
		return (new);
	if (infos_struct->precision != -1)
		new = apply_precision(infos_struct, &new);
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
	if (conv == 'c')
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
		str = p_converter(infos);
	return (str);
}

char	*ft_translate_format(t_infos *infos_struct, va_list *infos,
int *n_writt_char)
{
	char	*str;

	if (infos_struct->valid == 0)
		return (infos_struct->invalid);
	str = translate_converter(infos_struct, infos, n_writt_char);
	if (str != NULL)
		str = translate_flags(infos_struct, &str);
	return (str);
}
