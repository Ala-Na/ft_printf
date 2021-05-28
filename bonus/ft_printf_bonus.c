/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:01:14 by elanna            #+#    #+#             */
/*   Updated: 2021/05/28 23:31:35 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	printf_char(char **str, int *n_writt_char, char is_char)
{
	int		i;
	size_t	to_print;

	to_print = ft_strlen(*str);
	i = 0;
	if (is_char == -1 && (*str)[i] == 0)
	{
		to_print += 1;
		i++;
	}
	while ((*str)[i++] == ' ')
	{
		if (is_char == -1 && (*str)[0] == 0)
		{
			to_print += 1;
			*n_writt_char += 1;
		}
	}
	if (is_char == 1 && ((to_print > 1 && (*str)[to_print - 1] == 0) 
		|| *str[0] == 0))
		to_print += 1;
	if (is_char > 1 && (*str)[to_print] == 0)
		to_print += 1;
	ft_putlenstr_fd(*str, 1, to_print);
}

static void	printf_str(char **str, int *n_writt_char, char is_char)
{
	size_t	to_print;

	to_print = ft_strlen(*str);
	*n_writt_char += to_print;
	if (*str && is_char != 0)
		printf_char(str, n_writt_char, is_char);
	else
		ft_putstr_fd(*str, 1);
	free(*str);
}

static void	printf_non_format_char(char curr_char, int *n_writt_char)
{
	ft_putchar(curr_char);
	*n_writt_char += 1;
}

void	get_infos_bonus(const char **format, va_list *infos, int *n_writt_char,
char *is_char)
{
	t_infos	*infos_struct;
	char	*str;

	infos_struct = parse_format(format, infos);
	if (infos_struct->converter == 'c')
	{
		*is_char = 1;
		if (infos_struct->minus == 1)
			*is_char = -1;
	}
	if (infos_struct && !(ft_strchr("cs", infos_struct->converter)
		&& infos_struct->length == 1))
	{
		str = ft_translate_format(infos_struct, infos, n_writt_char);
		if (str)
			printf_str(&str, n_writt_char, *is_char);
	}
	else if (infos_struct)
	{
		str = ft_translate_special_format(infos_struct, infos, n_writt_char);
		if (str && *n_writt_char != -1)
			printf_str(&str, n_writt_char, *is_char);
	}
	if (infos_struct)
	{
		if (infos_struct->valid == 1 && infos_struct->invalid)
			free(infos_struct->invalid);
		free(infos_struct);
	}
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
