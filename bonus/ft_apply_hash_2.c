/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:23:27 by elanna            #+#    #+#             */
/*   Updated: 2021/05/29 01:23:50 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	fill_hashed_g(char **str, char **hash, int s_nbr, int precision)
{
	int	i;
	int	y;

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

char	*apply_hash_on_g(int precision, char **str)
{
	int		i;
	int		s_nbr;
	char	*hash;

	i = 0;
	s_nbr = 0;
	if (precision == -1)
		precision = 6;
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
	hash = malloc(sizeof(*hash) * (ft_strlen(*str) + precision - s_nbr + 1));
	if (!hash)
		return (NULL);
	fill_hashed_g(str, &hash, s_nbr, precision);
	return (hash);
}
