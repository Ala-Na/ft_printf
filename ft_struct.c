/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:46:53 by elanna            #+#    #+#             */
/*   Updated: 2021/04/15 11:57:50 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Toutes les valeurs sont placées à 0. 
//Les valeurs binaires (présent ou non présent) seront mise à 1.
//field est placé par -1 par défaut (=taille nécessaire), 
//sinon sa valeur.
//precision est initialisée à 0, selon le man, sauf spécifiée.
//valid permet juste de stocker si une erreur de format a été
//rencontrée. Si oui, tout est write tel quel à l'exception
//des length modifier, en étant stocké dans la string invalid.
t_infos	*init_infos_struct()
{
	t_infos	*infos_struct;

	if (!(infos_struct = malloc(sizeof(t_infos))))
		return (NULL);
	infos_struct->valid = 0;
	infos_struct->invalid = NULL;
	infos_struct->minus = 0;
	infos_struct->zero = 0;
	infos_struct->hash = 0;
	infos_struct->plus = 0;
	infos_struct->space = 0;
	infos_struct->field = -1;
	infos_struct->precision = -1;
	infos_struct->length = 0;
	infos_struct->converter = 0;
	infos_struct->format_size = 0;
	return (infos_struct);
}
