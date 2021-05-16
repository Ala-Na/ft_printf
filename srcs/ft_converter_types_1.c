/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_types_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:53:07 by elanna            #+#    #+#             */
/*   Updated: 2021/05/16 20:59:31 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_converter(va_list *infos, int *n_writt_char)
{
	char	*str;

	if (!(str = malloc(sizeof(*str) * 2)))
		return (NULL);
	str[0] = (char)va_arg(*infos, int);
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

	tmp = (char*)va_arg(*infos, char*);
	if (tmp == NULL)
		tmp = "(null)";
	size = ft_strlen(tmp);
	if (!(str = malloc(sizeof(*str) * (size + 1))))
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

	if (!(str = malloc(sizeof(*str) * 2)))
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char	*p_converter(va_list *infos)
{
	char	*str;
	void	*addr;

	addr = (void*)va_arg(*infos, void*);
	if (addr == 0)
		str = ft_strdup("(nil)");
	else
		str = ft_hexaddr(addr);
	return (str);
}

char	*n_converter(va_list *infos, int n_writt_char)
{
	int *ptr;

	ptr = (int*)va_arg(*infos, int*);
	*ptr = n_writt_char;
	return (NULL);
}
