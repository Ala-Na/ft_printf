/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitobase_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 22:26:48 by elanna            #+#    #+#             */
/*   Updated: 2021/05/20 15:15:21 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function which turn an unsigned int into an ascii
** string according to a given base.
** Careful : This does not check if the base is valid (no repetitions).
*/

#include "libft_bonus.h"

static int	ft_det_size_uitobase(unsigned int n, unsigned int base_size)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

char	*ft_uitobase(unsigned int n, char *base)
{
	char			*arr;
	int				i;
	unsigned int	base_size;

	i = 0;
	base_size = 0;
	while (base[i++] != '\0')
		base_size++;
	i = ft_det_size_uitobase(n, base_size);
	arr = malloc(sizeof(*arr) * (i + 1));
	if (!arr)
		return (0);
	arr[i] = 0;
	if (n == 0)
		arr[0] = base[0];
	while (n > 0)
	{
		arr[--i] = base[n % base_size];
		n /= base_size;
	}
	return (arr);
}
