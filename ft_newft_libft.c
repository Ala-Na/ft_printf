/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newft_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:42:53 by elanna            #+#    #+#             */
/*   Updated: 2021/04/14 20:55:30 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_det_size_uitoa(unsigned int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_uitoa(unsigned int n)
{
	char			*arr;
	unsigned int	i;

	i = ft_det_size_uitoa(n);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	if (n == 0)
		arr[0] = '0';
	while (n != 0)
	{
		arr[--i] = '0' + (n % 10);
		n /= 10;
	}
	return (arr);
}

static int	ft_det_size_uitobase(unsigned int n, unsigned int base_size)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

char		*ft_uitobase(unsigned int n, char *base)
{
	char			*arr;
	unsigned int	i;
	unsigned int	base_size;

	i = 0;
	base_size = 0;
	while (base[i++] != '\0')
		base_size++;
	i = ft_det_size_uitobase(n, base_size);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	if (n == 0)
		arr[0] = base[0];
	while (n != 0)
	{
		arr[--i] = base[n % base_size];
		n /= base_size;
	}
	return (arr);
}

static int	ft_det_size_hexaddr(size_t a_value)
{
	int	size;

	if (a_value == 0)
		return (1);
	size = 0;
	while (a_value != 0)
	{
		size++;
		a_value /= 16;
	}
	return (size);
}

char	*ft_hexaddr(void *addr)
{
	char	*arr;
	char	*full_arr;
	int		i;
	char	*base;
	size_t	a_value;

	base = "0123456789abcdef";
	a_value = (size_t)addr;
	i = ft_det_size_hexaddr(a_value);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	if (a_value == 0)
		arr[0] = base[0];
	while (a_value != 0)
	{
		arr[--i] = base[a_value % 16];
		a_value /= 16;
	}
	full_arr = ft_strjoin("0x", arr);
	free(arr);
	return (full_arr);
}
