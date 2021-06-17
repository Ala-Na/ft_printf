/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:23:27 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 16:25:12 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*fill_hashed_g(char **str, int s_nbr, int precision)
{
	char	*hash;
	int		i;
	int		y;

	i = 0;
	y = 0;
	hash = malloc(sizeof(*hash) * (ft_strlen(*str) + precision - s_nbr + 1));
	if (!hash)
		return (NULL);
	if ((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ')
		hash[y++] = (*str)[i++];
	while (((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.')
		hash[y++] = (*str)[i++];
	while (s_nbr++ < precision)
		hash[y++] = '0';
	while ((*str)[i] != 0)
		hash[y++] = (*str)[i++];
	hash[y] = 0;
	free(*str);
	return (hash);
}

char	*apply_hash_on_g(int precision, char **str)
{
	int		i;
	int		s_nbr;

	i = 0;
	s_nbr = 0;
	if (precision == -1)
		precision = 6;
	if ((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ')
		i++;
//	while ((*str)[i] == '0' || (*str)[i] == '.')
//		i++;
//	if ((*str)[i] == 0)
//		precision -= 1;
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
	return (fill_hashed_g(str, s_nbr, precision));
}
