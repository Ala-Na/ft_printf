/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:30:02 by elanna            #+#    #+#             */
/*   Updated: 2021/05/09 23:36:45 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_hashed_g(char **str, char **hash, int s_nbr, int precision)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.')
		(*hash)[y++] = (*str)[i++];
	while (s_nbr++ < precision)
		(*hash)[y++] = '0';
	while ((*str)[i] != 0)
		(*hash)[y++] = (*str)[i++];
	(*hash)[y] = 0;
	free(*str);
}

static char	*apply_hash_on_g(int precision, char **str)
{
	int		i;
	int		y;
	int		s_nbr;
	char	*hash;

	i = 0;
	y = 0;
	s_nbr = 0;
	while ((*str)[0] == '0' && ((*str)[i] == '0' || (*str)[i] == '.'))
		i++;
	while (((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.')
	{
		if ((*str)[i] != '.')
			s_nbr++;
		i++;
	}
	if ((*str)[2] == 0)
		s_nbr = 1;
	if (s_nbr >= precision)
		return (*str);
	if (!(hash = malloc(sizeof(*hash) *
		(ft_strlen(*str) + precision - s_nbr + 1))))
		return (NULL);
	fill_hashed_g(str, &hash, s_nbr, precision);
	return (hash);
}

static void	hash_exp_case(char *str, char **hash_str)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (!(*hash_str = malloc(sizeof(**hash_str) * (ft_strlen(str) + 2))))
		return ;
	while (str[i] != 0)
	{
		(*hash_str)[y++] = str[i++];
		if (str[i] == 'e')
			(*hash_str)[y++] = '.';
	}
	(*hash_str)[y] = 0;
}

char	*apply_hash(t_infos *infos_struct, char *str)
{
	char	conv;
	char	*hash_str;

	conv = infos_struct->converter;
	if (conv != 'e' && conv != 'f' && conv != 'g' && !(ft_strchr(str, 'i')) && !(ft_strchr(str, 'n')))
		return (str);
	hash_str = str;
	if (!(ft_strchr(str, '.')))
	{
		if (ft_strchr(str, 'e'))
			hash_exp_case(str, &hash_str);
		else 
			hash_str = add_chars_to_mall_str(str, ".", 'e');
		free(str);
	}
	if (conv == 'g')
		hash_str = apply_hash_on_g(infos_struct->precision, &hash_str);
	return (hash_str);
}
