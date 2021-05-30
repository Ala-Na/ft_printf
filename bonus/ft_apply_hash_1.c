/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:30:02 by elanna            #+#    #+#             */
/*   Updated: 2021/05/29 16:21:13 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*hash_exp_case(char *str)
{
	int		i;
	int		y;
	char	*hash_str;

	i = 0;
	y = 0;
	hash_str = malloc(sizeof(*hash_str) * (ft_strlen(str) + 2));
	if (!(hash_str))
		return (NULL);
	while (str[i] != 0)
	{
		hash_str[y++] = str[i++];
		if (str[i] == 'e')
			hash_str[y++] = '.';
	}
	hash_str[y] = 0;
	return (hash_str);
}

char	*hash_grand_x_case(char **str, int precision)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (precision != -1 && (*str)[0] == '0'
		&& (*str)[1] == '1' && (*str)[2] != 0)
	{
		(*str)[1] = 'X';
		return (*str);
	}
	if (precision == 0 && ((*str)[0] == 0
		|| ((*str)[0] == '0' && (*str)[1] == 0)))
		tmp = ft_strdup("");
	while ((*str)[i] == '0')
		i++;
	if ((*str)[i] == 0)
	{
		if (tmp)
			free(tmp);
		return (*str);
	}
	tmp = ft_strjoin("0X", *str);
	free(*str);
	return (tmp);
}

char	*hash_x_case(char **str, int precision)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (precision != -1 && (*str)[0] == '0'
		&& (*str)[1] == '1' && (*str)[2] != 0)
	{
		(*str)[1] = 'x';
		return (*str);
	}
	if (precision == 0 && ((*str)[0] == 0
		|| ((*str)[0] == '0' && (*str)[1] == 0)))
		tmp = ft_strdup("");
	while ((*str)[i] == '0')
		i++;
	if ((*str)[i] == 0)
	{
		if (tmp)
			free(tmp);
		return (*str);
	}
	tmp = ft_strjoin("0x", *str);
	free(*str);
	return (tmp);
}

char	*apply_hash(t_infos *infos_struct, char **str)
{
	char	conv;
	char	*hash_str;

	conv = infos_struct->converter;
	if (conv == 'x')
		return (hash_x_case(str, infos_struct->precision));
	else if (conv == 'X')
		return (hash_grand_x_case(str, infos_struct->precision));
	if ((conv != 'e' && conv != 'f' && conv != 'g') || ft_strchr(*str, 'i')
		|| ft_strchr(*str, 'n'))
		return (*str);
	hash_str = *str;
	if (!(ft_strchr(*str, '.')))
	{
		if (ft_strchr(*str, 'e'))
		{
			hash_str = hash_exp_case(*str);
			free(*str);
		}
		else
			hash_str = add_chars_to_mall_str(*str, ".", 'e');
	}
	if (conv == 'g')
		hash_str = apply_hash_on_g(infos_struct->precision, &hash_str);
	return (hash_str);
}
