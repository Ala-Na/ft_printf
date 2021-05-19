/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:22:08 by elanna            #+#    #+#             */
/*   Updated: 2021/05/19 22:47:42 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

void			parse_length_double(char length_code,
t_infos *infos_struct, char **s);
char			*parse_length(t_infos *infos_struct, char *str);
void	parse_bonus_flags(t_infos *infos_struct, char *s);

void			translate_converter_bonus(char **str,
t_infos *infos_struct, va_list *infos, int *n_writt_char);

char			*n_converter(va_list *infos, char length, int n_writt_char);
char			*f_converter(va_list *infos, int precision);
char			*e_converter(va_list *infos, int precision);
char			*g_converter(va_list *infos, int precision);

char			*apply_space(t_infos *infos_struct, char **str);
char			*apply_plus(t_infos *infos_struct, char **str);
char			*apply_hash(t_infos *infos_struct, char **str);

#endif
