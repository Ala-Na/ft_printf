/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:24:07 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 23:58:36 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*special_c_converter(va_list *infos, int *n_writt_char)
{
	wchar_t	*spe_str;

	spe_str = malloc(sizeof(*spe_str) * 2);
	if (!spe_str)
		return (NULL);
	spe_str[0] = (wchar_t)va_arg(*infos, wint_t);
	spe_str[1] = '\0';
	if (spe_str[0] == 0)
		*n_writt_char += 1;
	return (spe_str);
}

wchar_t	*special_s_converter(va_list *infos)
{
	wchar_t	*tmp;
	wchar_t	*spe_str;
	size_t	size;

	tmp = va_arg(*infos, wchar_t *);
	if (tmp == NULL)
		tmp = (wchar_t *)(ft_strdup("(null)"));
	size = 0;
	while (tmp[size] != 0)
		size++;
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
