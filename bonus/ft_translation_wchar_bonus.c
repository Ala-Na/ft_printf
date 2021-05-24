/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation_wchar_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:52:28 by elanna            #+#    #+#             */
/*   Updated: 2021/05/24 22:02:01 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

wint_t	*ft_translate_special_format(t_infos *infos_struct, va_list *infos,
int *n_writt_char)
{
	wint_t	*spe_str;

	if (infos_struct->valid == 0)
		return ((wint_t *)infos_struct->invalid);
	if (infos_struct->converter == 'c')
		spe_str = special_c_converter(infos, n_writt_char);
	else
		spe_str = (wint_t *)special_s_converter(infos);
	if (spe_str != NULL)
	{
		if (infos_struct->precision != -1)
			spe_str = apply_special_precision(infos_struct, &spe_str);
		if (infos_struct->minus == 1)
			spe_str = apply_special_minus(infos_struct, &spe_str);
		else if (infos_struct->field != -1)
			spe_str = apply_special_field_width(infos_struct, &spe_str);
	}
	return (spe_str);
}

void	printf_special_char(wint_t **spe_str, int *n_writt_char, char is_char)
{
	int		i;
	size_t	to_print;

	to_print = ft_strlen((char *)*spe_str);
	i = 0;
	if (is_char == -1 && (*spe_str)[i] == 0)
	{
		to_print += 1;
		i++;
	}
	while ((*spe_str)[i++] == ' ')
	{
		if (is_char == -1 && (*spe_str)[0] == 0)
		{
			to_print += 1;
			*n_writt_char += 1;
		}
	}
	if (is_char == 1 && ((to_print > 1 && (*spe_str)[to_print - 1] == 0)
		|| (*spe_str)[0] == 0))
		to_print += 1;
	write(1, &(*spe_str), to_print);
}

void	printf_special_str(wint_t **spe_str, int *n_writt_char, char is_char)
{
	size_t	to_print;

	to_print = ft_strlen((char *)*spe_str);
	*n_writt_char += to_print;
	if (*spe_str && is_char != 0)
		printf_special_char(spe_str, n_writt_char, is_char);
	else
		write(1, &(*spe_str), to_print);
	free(*spe_str);
}