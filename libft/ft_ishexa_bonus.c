/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:50:26 by elanna            #+#    #+#             */
/*   Updated: 2021/05/20 14:03:18 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function to know if a char is inside an hexadecimal format (with min or maj).
*/

#include "libft_bonus.h"

int	ft_ishexa(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F'))
		return (c);
	return (0);
}
