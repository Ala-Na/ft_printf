/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:14 by elanna            #+#    #+#             */
/*   Updated: 2021/05/19 15:25:56 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_infos(const char **format, va_list *infos, int *n_writt_char)
{
	t_infos	*infos_struct;
	char	*str;

	infos_struct = parse_format(format, infos);
	if (infos_struct)
	{
		str = ft_translate_format(infos_struct, infos, n_writt_char);
		if (infos_struct->valid == 1 && infos_struct->invalid)
			free(infos_struct->invalid);
		free(infos_struct);
	}
	return (str);
}

static void	printf_str(char **str, int *n_writt_char)
{
	*n_writt_char += ft_strlen(*str);
	ft_putstr_fd(*str, 1);
	free(*str);
}

static void	printf_char(char curr_char, int *n_writt_char)
{
	ft_putchar(curr_char);
	*n_writt_char += 1;
}

int			ft_printf(const char *format, ...)
{
	va_list	infos;
	int		n_writt_char;
	char	curr_char;
	char	*str;

	va_start(infos, format);
	n_writt_char = 0;
	while (*format != '\0')
	{
		curr_char = *format;
		format++;
		if (curr_char != '%')
			printf_char(curr_char, &n_writt_char);
		else
		{
			str = get_infos(&format, &infos, &n_writt_char);
			if (str)
				printf_str(&str, &n_writt_char);
		}
	}
	va_end(infos);
	return (n_writt_char);
}
