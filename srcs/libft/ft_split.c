/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:01:20 by anadege           #+#    #+#             */
/*   Updated: 2021/03/23 15:41:37 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_init(char const *s, char c)
{
	size_t	i;
	size_t	occ;
	char	**arr;

	i = 0;
	occ = 0;
	while (s && s[i])
	{
		if (i == 0 && s[i] != c)
			occ++;
		else if (i - 1 > 0 && s[i - 1] == c && s[i] != c)
			occ++;
		i++;
	}
	if (!(arr = malloc(sizeof(*arr) * (occ + 1))))
		return (0);
	arr[occ] = 0;
	return (arr);
}

static char	*ft_split_dup(char const *s, char c)
{
	size_t	str_size;
	char	*str;

	str_size = 0;
	while (s[str_size] && s[str_size] != c)
		str_size++;
	if (!(str = malloc(sizeof(*str) * (str_size + 1))))
		return (0);
	str_size = 0;
	while (s[str_size] && s[str_size] != c)
	{
		str[str_size] = s[str_size];
		str_size++;
	}
	str[str_size] = 0;
	return (str);
}

char		**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	i;
	int		start;
	char	**arr;

	if (!(arr = ft_split_init(s, c)))
		return (0);
	i = -1;
	size = 0;
	while (s && s[++i])
	{
		start = ((i == 0 || s[i - 1] == c) ? 1 : 0);
		if (s[i] != c && start == 1)
		{
			start = 0;
			if (!(arr[size++] = ft_split_dup(s + i, c)))
			{
				while (--size > 0)
					free(arr[size--]);
				free(arr);
				return (0);
			}
		}
	}
	return (arr);
}
