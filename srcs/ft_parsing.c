/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:16:00 by elanna            #+#    #+#             */
/*   Updated: 2021/06/17 23:59:29 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_conversion_specifier = "cspdiuxXfgen%";
char	*g_flags = "-0#+ ";

/*
** Function to visualize the content of struct
**
** void	print_struct_content(t_infos *istruct)
**{
**	printf("start printing\n");
**	printf("valid : %i\n", (int)istruct->valid);
**	printf("invalid : %s\n", istruct->invalid);
**	printf("minus : %i\n", (int)istruct->minus);
**	printf("zero : %i\n", (int)istruct->zero);
**	printf("hash : %i\n", (int)istruct->hash);
**	printf("plus : %i\n", (int)istruct->plus);
**	printf("space : %i\n", (int)istruct->space);
**	printf("field : %i\n", istruct->field);
**	printf("precision : %i\n", istruct->precision);
**	printf("length : %i\n", (int)istruct->length);
**	printf("converter : %c\n", istruct->converter);
**	printf("format size : %i\n", istruct->format_size);
**}
*/

void	stock_infos_parsed(t_infos *infos_struct, char c)
{
	char	*tmp;
	char	s[2];

	s[0] = c;
	s[1] = '\0';
	if (infos_struct->invalid == NULL)
		infos_struct->invalid = ft_strdup(s);
	else
	{
		tmp = ft_strjoin(infos_struct->invalid, s);
		free(infos_struct->invalid);
		infos_struct->invalid = tmp;
	}
	infos_struct->format_size += 1;
}

char	*parse_converter(t_infos *infos_struct, char *str)
{
	char	*s;

	s = str;
	infos_struct->valid = 1;
	infos_struct->converter = *s;
	stock_infos_parsed(infos_struct, *s);
	s++;
	return (s);
}

t_infos	*parse_format(const char **format, va_list *infos)
{
	t_infos	*infos_struct;
	char	*s;

	infos_struct = init_infos_struct();
	if (!infos_struct)
		return (NULL);
	s = (char *)*format;
	while (ft_strchr(g_flags, (int)*s))
		s = parse_flags(infos_struct, s);
	if (*s == '*' || ft_isdigit(*s))
		s = parse_field_width(infos, infos_struct, s);
	if (*s == '.')
		s = parse_precision(infos, infos_struct, s);
	if (*s == 'l' || *s == 'h')
		s = parse_length(infos_struct, s);
	if (ft_strchr(g_conversion_specifier, *s))
		s = parse_converter(infos_struct, s);
	*format = s;
	return (infos_struct);
}

/*
** Brief test to see if struct if correctly filled
**
**void	ft_test(const char *str, ...)
**{
**	t_infos	*istruct;
**	va_list	list;
**	va_start(list, str);
**	istruct = parse_format(&str, &list);
**	print_struct_content(istruct);
**	free(istruct->invalid);
**	free(istruct);
**}
**
**int main()
**{
**	const char *str = "0#+ *.125hhc";
**	printf("Format is %s\n", str);
**	ft_test(str, 45);
**	return (0);
**}
*/
