/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:14 by elanna            #+#    #+#             */
/*   Updated: 2021/05/29 23:39:30 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	printf_non_format_char(char curr_char, int *n_writt_char)
{
	ft_putchar(curr_char);
	*n_writt_char += 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	infos;
	int		n_writt_char;
	char	curr_char;
	char	is_char;

	va_start(infos, format);
	n_writt_char = 0;
	while (*format != '\0')
	{
		curr_char = *format;
		format++;
		if (curr_char != '%')
			printf_non_format_char(curr_char, &n_writt_char);
		else
		{
			is_char = 0;
			get_infos_bonus(&format, &infos, &n_writt_char, &is_char);
			if (n_writt_char == -1)
				break ;
		}
	}
	va_end(infos);
	return (n_writt_char);
}
