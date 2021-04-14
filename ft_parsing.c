/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 21:34:53 by elanna            #+#    #+#             */
/*   Updated: 2021/04/14 11:11:32 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*FLAGS = "-0#+ ";
char	*CONVERSION_SPECIFIER = "cspdiuxX%nfge";

/*void	print_struct_content(t_infos *istruct)
{
	printf("start printing\n");
	printf("valid : %i\n", (int)istruct->valid);
	printf("invalid : %s\n", istruct->invalid);
	printf("minus : %i\n", (int)istruct->minus);
	printf("zero : %i\n", (int)istruct->zero);
	printf("hash : %i\n", (int)istruct->hash);
	printf("plus : %i\n", (int)istruct->plus);
	printf("space : %i\n", (int)istruct->space);
	printf("field : %i\n", istruct->field);
	printf("precision : %i\n", istruct->precision);
	printf("length : %i\n", (int)istruct->length);
	printf("converter : %c\n", istruct->converter);
	printf("format size : %i\n", istruct->format_size);
}*/

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

char *parse_converter(t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	infos_struct->valid = 1;
	infos_struct->converter = *s;
	stock_infos_parsed(infos_struct, *s);
	s++;
	return (s);
}

char	*parse_length(t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	if (*s == 'l')
	{
		s++;
		if (*s == 'l')
		{
			infos_struct->length = 3;
			infos_struct->format_size += 1;
			s++;
		}
		else
			infos_struct->length = 1;
	}
	else if (*s == 'h')
	{
		s++;
		if (*s == 'h')
		{
			infos_struct->length = 4;
			infos_struct->format_size += 1;
			s++;
		}
		else
			infos_struct->length = 2;
	}
	infos_struct->format_size += 1;
	return (s);
}

char	*parse_precision(t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	stock_infos_parsed(infos_struct, *s);
	s++;
	while (ft_isdigit(*s))
	{
		infos_struct->precision *= 10;
		infos_struct->precision += *s - '0';
		stock_infos_parsed(infos_struct, *s);
		s++;
	}
	return (s);
}

char *parse_field_width(va_list *infos, t_infos *infos_struct, char *str)
{
	char *s;

	s = str;
	if (*s == '*')
	{
		infos_struct->field = (int)va_arg(*infos, int);
		stock_infos_parsed(infos_struct, *s);
		s++;
	}
	else
	{
		while (ft_isdigit(*s))
		{
			if (infos_struct->field == -1)
				infos_struct->field = 0;
			infos_struct->field *= 10;
			infos_struct->field += *s - '0';
			stock_infos_parsed(infos_struct, *s);
			s++;
		}
	}
	return (s);
}

char	*parse_flags(t_infos *infos_struct, char *str)
{
	char	*s;

	s = str;
	if (*s == '-')
	{
		infos_struct->minus = 1;
		infos_struct->zero = 0;
	}
	else if (*s == '0' && infos_struct->minus == 0)
		infos_struct->zero = 1;
	else if (*s == '#')
		infos_struct->hash = 1;
	else if (*s == '+')
		infos_struct->plus = 1;
	else if (*s == ' ')
		infos_struct->space = 1;
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
	s = (char*)*format;
	while (ft_strchr(FLAGS, (int)*s))
		s = parse_flags(infos_struct, s);
	if (*s == '*' || ft_isdigit(*s))
		s = parse_field_width(infos, infos_struct, s);
	if (*s == '.')
		s = parse_precision(infos_struct, s);
	if (*s == 'l' || *s == 'h')
		s = parse_length(infos_struct, s);
	if (ft_strchr(CONVERSION_SPECIFIER, *s))
		s = parse_converter(infos_struct, s);
	return (infos_struct);
}

/*void	ft_test(const char *str, ...)
{
	t_infos	*istruct;
	va_list	list;
	va_start(list, str);
	istruct = parse_format(&str, &list);
	print_struct_content(istruct);
	free(istruct->invalid);
	free(istruct);
}

int main()
{
	const char *str = "0#+ *.125hhc";
	printf("Format is %s\n", str);
	ft_test(str, 45);
	return (0);
}*/
