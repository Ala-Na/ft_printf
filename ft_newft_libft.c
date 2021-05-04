/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newft_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:42:53 by elanna            #+#    #+#             */
/*   Updated: 2021/05/03 16:30:54 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_pow(unsigned long long nb, int power)
{
	if (power == 0)
		return (1);
	else if (power > 1)
		return ((unsigned long long)nb * ft_pow(nb, power - 1));
	else if (power == 1)
		return ((unsigned long long)nb);
	return (0);
}

static int	ft_det_size_uitoa(unsigned int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_uitoa(unsigned int n)
{
	char			*arr;
	int	i;

	i = ft_det_size_uitoa(n);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	if (n == 0)
		arr[0] = '0';
	while (n > 0)
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
	while (n > 0)
	{
		size++;
		n /= base_size;
	}
	return (size);
}

char		*ft_uitobase(unsigned int n, char *base)
{
	char			*arr;
	int	i;
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
	while (n > 0)
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
	while (a_value > 0)
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
	while (a_value > 0)
	{
		arr[--i] = base[a_value % 16];
		a_value /= 16;
	}
	full_arr = ft_strjoin("0x", arr);
	free(arr);
	return (full_arr);
}

static int	ft_det_size_llitoa(long long n)
{
	int				size;
	unsigned long long	nb;

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

char		*ft_llitoa(long long n)
{
	char			*arr;
	unsigned long long	nb;
	unsigned long long	i;

	i = ft_det_size_llitoa(n);
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

static int	ft_det_size_ullitoa(unsigned long long n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_ullitoa(unsigned long long n)
{
	char			*arr;
	int	i;

	i = ft_det_size_ullitoa(n);
	if (!(arr = malloc(sizeof(*arr) * (i + 1))))
		return (0);
	arr[i] = 0;
	if (n == 0)
		arr[0] = '0';
	while (n > 0)
	{
		arr[--i] = '0' + (n % 10);
		n /= 10;
	}
	return (arr);
}

static int	ft_det_size_ullitobase(unsigned long long n, unsigned long long base_size)
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

char		*ft_ullitobase(unsigned long long n, char *base)
{
	char			*arr;
	int	i;
	unsigned long long	base_size;

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
	while (n > 0)
	{
		arr[--i] = base[n % base_size];
		n /= base_size;
	}
	return (arr);
}

void	ft_print_bin_rep(size_t const size, void const *ptr)
{
	unsigned char *byte;
	unsigned char bit;
	int i;
	int j;

	byte = (unsigned char*)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			bit = (byte[i] >> j) & 1;
			ft_putnbr_fd(bit, 1);
			j--;
		}
		ft_putchar_fd(' ', 1);
		i--;
	}
	ft_putchar_fd(' ', 1);
}

unsigned long long	ft_bintodec(unsigned long long bin, int start)
{
	unsigned long long	dec;
	int	i;
	int	rest;

	dec = 0;
	i = start;
	while (bin != 0)
	{
		rest = bin & 1;
		bin = bin >> 1;
		dec += (rest * ft_pow(2, i));
		i++;
	}
	return (dec);
}
