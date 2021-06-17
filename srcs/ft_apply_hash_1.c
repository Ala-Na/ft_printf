/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:30:02 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 23:57:55 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	replace_by_x(char **str, int precision, char letter)
{
	int	i;

	i = 0;
	while ((*str)[i] == '0')
		i++;
	if ((*str)[i] == 0 || (*str)[i] == ' ')
		return (1);
	if ((precision != -1 && (*str)[0] == '0'
		&& (*str)[1] == '1' && (*str)[2] != 0))
	{
		(*str)[1] = letter;
		return (1);
	}
	return (0);
}

char	*hash_x_cases(char **str, int precision, char letter)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = replace_by_x(str, precision, letter);
	if (i == 1)
		return (*str);
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
	if (letter == 'x')
		tmp = ft_strjoin("0x", *str);
	else
		tmp = ft_strjoin("0X", *str);
	free(*str);
	return (tmp);
}

char	*apply_hash(t_infos *infos_struct, char **str)
{
	char	conv;
	char	*hash_str;

	conv = infos_struct->converter;
	if (conv == 'x' || conv == 'X')
		return (hash_x_cases(str, infos_struct->precision, conv));
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
