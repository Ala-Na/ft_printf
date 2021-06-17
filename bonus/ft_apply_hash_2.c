/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:23:27 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 22:47:59 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

/*char	*fill_hashed_g(char **str, int s_nbr, int precision)
{
	char	*hash;
	int		i;
	int		y;

	i = 0;
	y = 0;
	printf("str is %s, s_nbr is %i, precision is %i\n", *str, s_nbr, precision);
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
	while (((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.')
	{
		if ((*str)[i] != '.')
			s_nbr++;
		i++;
	}
	if ((*str)[2] == 0)
		s_nbr = 1;
	i = 2;
	while (ft_strlen(*str) >= 2 && (*str)[0] == '0' && (*str)[1] == '.' && (*str)[i] == '0')
		i++;
	if ((*str)[i] != 0 && i != 1)
		s_nbr -= 1;
	if (s_nbr >= precision)
		return (*str);
	return (fill_hashed_g(str, s_nbr, precision));
}*/

static char	*tmp_fill_hashed_g(char **str, int precision, int non_signi_digits, int not_digit)
{
	char	*hash;
	int	i;
	int	y;

	i = 0;
	y = 0;
	hash = malloc(sizeof(*hash) * (precision + non_signi_digits + not_digit + 1));
	if (!hash)
		return (NULL);
	if ((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ')
		hash[y++] = (*str)[i++];
	while ((*str)[i] != 0)
		hash[y++] = (*str)[i++];
	while (y < (precision + non_signi_digits + not_digit))
		hash[y++] = '0';
	hash[y] = 0;
	free(*str);
	return (hash);
}

char	*apply_hash_on_g(int precision, char **str)
{
	int	i;
	int	not_digit;
	int	signi_digits;

	i = 0;
	not_digit = 0;
	signi_digits = 0;
	if (precision == -1)
		precision = 6;
	if ((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ')
	{
		i++;
		not_digit += 1;
	}
	if ((*str)[i] == '0' && (*str)[i + 1] == '.' && (*str)[i + 2] == 0)
		precision -= 1;
	while (((*str)[i] >= '0' && (*str)[i] <= '9') || (*str)[i] == '.')
	{
		if ((*str)[i] == '.')
			not_digit += 1;
		else if (!((*str)[i] == '0' && signi_digits == 0))
			signi_digits += 1;
		i++;
	}
	if (signi_digits >= precision)
		return (*str);
	return (tmp_fill_hashed_g(str, precision, (i - signi_digits - not_digit), not_digit));
}
