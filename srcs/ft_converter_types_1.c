/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:53:07 by elanna            #+#    #+#             */
/*   Updated: 2021/06/02 11:50:06 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_converter(va_list *infos, int *n_writt_char)
{
	char	*str;

	str = malloc(sizeof(*str) * 2);
	if (!str)
		return (NULL);
	str[0] = va_arg(*infos, int);
	str[1] = '\0';
	if (str[0] == 0)
		*n_writt_char += 1;
	return (str);
}

char	*s_converter(va_list *infos)
{
	char	*tmp;
	char	*str;
	int		size;

	tmp = (char *)va_arg(*infos, char *);
	if (!tmp)
		tmp = "(null)";
	size = (int)ft_strlen(tmp);
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	size = 0;
	while (tmp[size] != 0)
	{
		str[size] = tmp[size];
		size += 1;
	}
	str[size] = '\0';
	return (str);
}

char	*percent_converter(void)
{
	char	*str;

	str = malloc(sizeof(*str) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

/*
** Under linux : change "0x0" for "(nil)" when addr == 0
*/
char	*p_converter(va_list *infos)
{
	char	*str;
	void	*addr;

	addr = (void *)va_arg(*infos, void *);
	if (addr == 0)
		str = ft_strdup("0x0");
	else
		str = ft_hexaddr(addr);
	return (str);
}
