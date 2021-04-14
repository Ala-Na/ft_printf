/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_needed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:46:12 by elanna            #+#    #+#             */
/*   Updated: 2021/04/14 11:28:28 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0 && *s == 0)
		return ((char *)s);
	return (NULL);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(dest = malloc(sizeof(*dest) * (size + 1))))
		return (0);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = -1;
	size = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	while (s1[size])
		size++;
	while (s2[++i])
		size++;
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (0);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[size] = 0;
	return (str);
}

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

