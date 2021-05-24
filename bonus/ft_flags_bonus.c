/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:29:57 by elanna            #+#    #+#             */
/*   Updated: 2021/05/23 21:10:27 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	parse_length_double(char length_code, t_infos *infos_struct, char **s)
{
	infos_struct->length = length_code;
	infos_struct->format_size += 1;
	(*s)++;
}

char	*parse_length(t_infos *infos_struct, char *str)
{
	char	*s;

	s = str;
	if (*s == 'l')
	{
		s++;
		if (*s == 'l')
			parse_length_double(3, infos_struct, &s);
		else
			infos_struct->length = 1;
	}
	else if (*s == 'h')
	{
		s++;
		if (*s == 'h')
			parse_length_double(4, infos_struct, &s);
		else
			infos_struct->length = 2;
	}
	infos_struct->format_size += 1;
	return (s);
}

void	parse_bonus_flags(t_infos *infos_struct, char *s)
{
	if (*s == '#')
		infos_struct->hash = 1;
	else if (*s == '+')
	{
		infos_struct->space = 0;
		infos_struct->plus = 1;
	}
	else if (*s == ' ' && infos_struct->plus == 0)
		infos_struct->space = 1;
}
