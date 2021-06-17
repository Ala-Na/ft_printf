/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation_wchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:52:28 by elanna            #+#    #+#             */
/*   Updated: 2021/06/18 00:00:33 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_values_wcrtombstr(size_t	*nbr_bytes, size_t *last,
mbstate_t *ps, char **mb_str)
{
	*nbr_bytes = 0;
	*last = 0;
	ft_memset(&(*ps), 0, sizeof(*ps));
	*mb_str = NULL;
}

static char	*wcrtombstr_error_case(int *n_writt_char, char **mb_str)
{
	*n_writt_char = -1;
	if (*mb_str)
		free(*mb_str);
	return (NULL);
}

char	*ft_wcrtombstr(wchar_t *w_str, int *n_writt_char, int precision,
char converter)
{
	mbstate_t	ps;
	size_t		last;
	size_t		nbr_bytes;
	char		mb[MB_CUR_MAX + 1];
	char		*mb_str;

	init_values_wcrtombstr(&nbr_bytes, &last, &ps, &mb_str);
	while (w_str && *w_str)
	{
		nbr_bytes = ft_wcrtomb(&mb[0], *w_str++, &ps);
		if (nbr_bytes == 0)
			return (wcrtombstr_error_case(n_writt_char, &mb_str));
		if (converter == 's' && precision != -1
			&& precision < (int)(last + nbr_bytes))
			break ;
		last += nbr_bytes;
		mb[nbr_bytes] = 0;
		if (!mb_str)
			mb_str = ft_strdup(mb);
		else
			mb_str = add_chars_to_mall_str(mb_str, &mb[0], 'e');
	}
	return (mb_str);
}

char	*ft_translate_special_format(t_infos *infos_struct, va_list *infos,
int *n_writt_char)
{
	wchar_t		*spe_str;
	char		*mb_str;

	if (infos_struct->valid == 0)
		return (infos_struct->invalid);
	if (infos_struct->converter == 'c')
		spe_str = special_c_converter(infos, n_writt_char);
	else
		spe_str = special_s_converter(infos);
	mb_str = ft_wcrtombstr(spe_str, n_writt_char, infos_struct->precision,
			infos_struct->converter);
	free(spe_str);
	if (mb_str && *n_writt_char != -1)
	{
		if (infos_struct->minus == 1)
			mb_str = apply_minus(infos_struct, &mb_str);
		else if (infos_struct->field != -1)
			mb_str = apply_field_width(infos_struct, &mb_str);
	}
	return (mb_str);
}
