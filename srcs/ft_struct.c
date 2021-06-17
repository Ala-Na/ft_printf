/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:46:53 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 23:59:46 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** All values are initially set at 0 (except 'field' and 'precision' at -1,
** to distinguish it from 0).
** Binary values are set to 1 when the corresponding flag is present.
** 'valid' is only useful to know if the format is valid, and if it can be
** translated. If not, the string '*invalid' can be print (but it does not
** contains length modifiers).
*/

t_infos	*init_infos_struct(void)
{
	t_infos	*infos_struct;

	infos_struct = malloc(sizeof(t_infos));
	if (!infos_struct)
		return (NULL);
	infos_struct->valid = 0;
	infos_struct->invalid = NULL;
	infos_struct->minus = 0;
	infos_struct->zero = 0;
	infos_struct->hash = 0;
	infos_struct->plus = 0;
	infos_struct->space = 0;
	infos_struct->field = -1;
	infos_struct->precision = -1;
	infos_struct->length = 0;
	infos_struct->converter = 0;
	infos_struct->format_size = 0;
	return (infos_struct);
}
