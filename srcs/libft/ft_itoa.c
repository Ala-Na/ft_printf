/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:40:29 by anadege           #+#    #+#             */
/*   Updated: 2021/03/10 12:00:38 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_det_size(int n)
{
	int				size;
	unsigned int	nb;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 0)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char			*arr;
	unsigned int	nb;
	unsigned int	i;

	i = ft_det_size(n);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	nb = 0;
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
	{
		arr[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	while (nb > 0)
	{
		arr[--i] = '0' + (nb % 10);
		nb /= 10;
	}
	return (arr);
}
