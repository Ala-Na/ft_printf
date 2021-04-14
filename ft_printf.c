/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:14 by elanna            #+#    #+#             */
/*   Updated: 2021/04/13 15:06:27 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	infos;
	va_start(infos, format);

	int	n_writt_char;
	char	curr_char;

	n_writt_char = 0;
	while (*format != '\0')
	{
		curr_char = *format;
		format++;
		if (curr_char != '%')
		{
			ft_putchar(curr_char);
			n_writt_char++;
			continue ;
		}
		else
		{
			//parse et print
		}
	}
	va_end(infos);
	return (n_writt_char);
}
