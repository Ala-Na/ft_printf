/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:56:16 by elanna            #+#    #+#             */
/*   Updated: 2021/03/22 21:38:25 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
