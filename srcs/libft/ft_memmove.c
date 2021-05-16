/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:46:04 by anadege           #+#    #+#             */
/*   Updated: 2021/03/21 15:42:27 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*s_tmp;
	char		*d_tmp;

	s_tmp = (const char *)src;
	d_tmp = (char *)dst;
	if (!n)
		return (dst);
	if (d_tmp <= s_tmp)
		while (n != 0)
		{
			*d_tmp++ = *s_tmp++;
			n--;
		}
	else
	{
		s_tmp += n;
		d_tmp += n;
		while (n != 0)
		{
			*--d_tmp = *--s_tmp;
			n--;
		}
	}
	return (dst);
}
