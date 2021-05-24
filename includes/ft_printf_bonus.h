/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:22:08 by elanna            #+#    #+#             */
/*   Updated: 2021/05/24 22:03:19 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"
# include <wchar.h>

void				get_infos_bonus(const char **format, va_list *infos, int *n_writt_char, char *is_char);

/*
** Functions additionnals for bonus fonctionment
*/
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

wint_t	*ft_translate_special_format(t_infos *infos_struct, va_list *infos,
int *n_writt_char);

wint_t	*special_c_converter(va_list *infos, int *n_writt_char);
wchar_t *special_s_converter(va_list *infos);
wint_t	*apply_special_minus(t_infos *infos_struct, wint_t **spe_str);
wint_t	*apply_special_precision(t_infos *infos_struct, wint_t **spe_str);
wint_t	*apply_special_field_width(t_infos *infos_struct, wint_t **spe_str);

void	printf_special_str(wint_t **spe_str, int *n_writt_char, char is_char);
void	printf_special_char(wint_t **spe_str, int *n_writt_char, char is_char);


#endif
