/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:01:55 by elanna            #+#    #+#             */
/*   Updated: 2021/05/13 15:51:39 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_content	*ft_contnew(char *buffer, int fd)
{
	t_content	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->buffer = ft_strdup(buffer);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

void		ft_contadd_back(t_content **alst, t_content *new)
{
	t_content *last;

	if (!new)
		return ;
	else if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = *alst;
	while (last->next)
		last = last->next;
	last->next = new;
}
