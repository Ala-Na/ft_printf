/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 01:23:27 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 23:02:08 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*fill_hashed_g(char **str, int precision, int non_signi_digits,
			int not_digit)
{
	char	*hash;
	int		i;
	int		y;

	i = 0;
	y = 0;
	hash = malloc(sizeof(*hash) * (precision + non_signi_digits
				+ not_digit + 1));
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

int	get_nbr_signi_digits(char **str, int *i, int *not_digit)
{
	int	signi_digits;

	signi_digits = 0;
	while (((*str)[*i] >= '0' && (*str)[*i] <= '9') || (*str)[*i] == '.')
	{
		if ((*str)[*i] == '.')
			*not_digit += 1;
		else if (!((*str)[*i] == '0' && signi_digits == 0))
			signi_digits += 1;
		*i += 1;
	}
	return (signi_digits);
}

char	*apply_hash_on_g(int precision, char **str)
{
	int	i;
	int	not_digit;
	int	signi_digits;

	i = 0;
	not_digit = 0;
	if (precision == -1)
		precision = 6;
	if ((*str)[i] == '+' || (*str)[i] == '-' || (*str)[i] == ' ')
	{
		i++;
		not_digit += 1;
	}
	if ((*str)[i] == '0' && (*str)[i + 1] == '.' && (*str)[i + 2] == 0)
		precision -= 1;
	signi_digits = get_nbr_signi_digits(str, &i, &not_digit);
	if (signi_digits >= precision)
		return (*str);
	return (fill_hashed_g(str, precision, (i - signi_digits - not_digit),
			not_digit));
}
