/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:54:56 by elanna            #+#    #+#             */
/*   Updated: 2021/05/04 16:24:27 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_exp(int exp, char *number)
{
	char	*str_exp;
	char	intro_exp[3];
	int	i;
	
	i = 0;
	intro_exp[i++] = 'e';
	if (exp >= 0)
		intro_exp[i++] = '+';
	else
	{
		intro_exp[i++] = '-';
		exp = -exp;
	}
	if (exp < 10)
		intro_exp[i++] = '0';
	intro_exp[i] = 0;
	str_exp = add_chars_to_mall_str(ft_itoa(exp), intro_exp, 'f');
	number = add_chars_to_mall_str(number, str_exp, 'e');
	free(str_exp);
	return (number);

}

void	fill_round_exp_number(char **number, int size, int num_size)
{
	int	i;
	int	y;
	int	limit_size;
	char	*round_number;

	i = 0;
	y = 0;
	if (!(round_number = malloc(sizeof(*round_number) * (size + 1))))
	{
		free(*number);
		*number = NULL;
		return ;
	}
	if (num_size < size)
		limit_size = num_size;
	else
		limit_size = size;
	if ((*number)[0] != 0)
		round_number[i++] = (*number)[y++];
	else
		round_number[i++] = '0';
	if (size > 1)
		round_number[i++] = '.';
	while (i < limit_size)
		round_number[i++] = (*number)[y++];
	while (i < size)
		round_number[i++] = '0';
	round_number[size] = 0;
	free(*number);
	*number = round_number;
}

void	do_exp_rounding(char **number, int *exp, int precision)
{
	int	i;
	int	size;
	int	num_size;

	size = precision + 1;
	i = size;
	if (precision != 0)
		size += 1;
	num_size = ft_strlen(*number);
	if (i <= num_size)
	{
		if ((*number)[i] >= '5' && (*number)[i] <= '9')
		{
			(*number)[--i] += 1;
			while (i >= 0 && (*number)[i] > '9')
			{
				if (i > 0)
				{
					(*number)[i--] = '0';
					(*number)[i] += 1;
				}
				else if (i == 0)
				{
					(*number)[i] = '0';
					*number = add_chars_to_mall_str(*number, "1", 'f');
					*exp += 1;
					break ;
				}
			}
		}
	}
	fill_round_exp_number(number, size, num_size);
}

char	*get_round_exp_number(char *int_part, char *frac_part, int precision)
{
	int	exp;
	char	*number;
	
	exp = 0;
	if (int_part[0] != '0')
	{
		exp = ft_strlen(int_part) - 1;
		number = ft_strjoin(int_part, frac_part);
	}
	else
	{
		while (*frac_part == '0')
		{
			exp--;
			frac_part++;
		}
		if (*frac_part != 0)
			exp --;
		else
			exp = 0;
		number = ft_strdup(frac_part);
	}
	do_exp_rounding(&number, &exp, precision);
	number = add_exp(exp, number);
	return (number);
}

char	*get_dtoa_exp_number(unsigned long long mant, short exp, int precision)
{
	char	*number;
	char	*int_part;
	char	*frac_part;

	if (exp == -1023)
	{
		mant = mant << 12;
		int_part = ft_strdup("0");
	}
	else
	{
		mant = mant << 11;
		mant = mant | 0x8000000000000000;
		int_part = get_int_part(mant, exp);
	}
	frac_part = get_frac_part(mant, exp);
	number = get_round_exp_number(int_part, frac_part, precision);
	free(int_part);
	free(frac_part);
	return (number);
}

char	*ft_dtoa_with_exp(double dbl, int precision)
{
	short				sign;
	short				exp;
	unsigned long long	mant;
	dbl_union			dbl_rep;
	char				*number;

	dbl_rep.d = dbl;
	sign = dbl_rep.l >> 63;
	exp = ((dbl_rep.l << 1) >> 53) - 1023;
	mant = ((dbl_rep.l << 12) >> 12);
	if (exp == 1024 && mant == 0)
		number = ft_strdup("inf");
	else if (exp == 1024 && mant != 0)
		number = ft_strdup("nan");
	else
		number = get_dtoa_exp_number(mant, exp, precision);
	if (sign == 1)
		number = add_chars_to_mall_str(number, "-", 'f');
	return (number);
}


/*void test(double nbr)
{
	printf("dbl e : %.0e\n", nbr);
	char *str = ft_dtoa_with_exp(nbr, 0);
	printf("mine :  %s\n\n", str);
	free(str);
	printf("dbl e : %.1e\n", nbr);
	str = ft_dtoa_with_exp(nbr, 1);
	printf("mine :  %s\n\n", str);
	free(str);
	printf("dbl e : %.3e\n", nbr);
	str = ft_dtoa_with_exp(nbr, 3);
	printf("mine :  %s\n\n", str);
	free(str);
	printf("dbl e : %.12e\n", nbr);
	str = ft_dtoa_with_exp(nbr, 12);
	printf("mine :  %s\n\n", str);
	free(str);

}

int	main()
{
	test(999.99999);
	test(-INFINITY);
	test(NAN);
	test(0.0000000000000086);
	test(0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000004);
	test(2.54);
	test(2.49);
	test(0.0);
	test(154.987456622358632);
	test(425896315587899);
	test(22222222228963214522222222222222222222.20);
}*/
