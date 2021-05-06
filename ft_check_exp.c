/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:36:49 by elanna            #+#    #+#             */
/*   Updated: 2021/05/06 17:10:25 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	del_last_zero(char **number, int size)
{
	int		nbr_zero;
	int		i;
	int		y;
	char	*tmp;

	i = size - 1;
	y = 0;
	nbr_zero = 0;
	while ((*number)[i] == '0')
	{
		nbr_zero++;
		i--;
	}
	if ((*number)[i] == '.')
		nbr_zero++;
	if (nbr_zero == 0 || !(tmp = malloc(sizeof(*tmp) * (size - nbr_zero + 1))))
		return ;
	i = 0;
	while (i < (size - nbr_zero))
		tmp[y++] = (*number)[i++];
	tmp[y] = 0;
	free(*number);
	*number = tmp;
}

void	exp_after_rounding(char **number, int *exp, int precision, int int_size)
{
	int	i;
	int	size;
	int	num_size;

	size = precision + 1 - int_size;
	i = size;
	if (precision != 0)
		size += 1;
	num_size = ft_strlen(*number);
	if (i <= num_size)
	{
		if ((*number)[i] >= '5' && (*number)[i] <= '9')
		{
			while (--i >= 0 && (*number)[i] == '9')
			{
				if (i > 0)
					i--;
				else if (i == 0)
				{
					*exp += 1;
					break ;
				}
			}
		}
	}
}

char	*check_exp_for_format(int exp, char *int_part, char *frac_part,
int precision)
{
	char	*number;
	int		int_size;

	int_size = ft_strlen(int_part);
	if (exp >= 0 && int_part[0] != '0')
		number = ft_strjoin(int_part, frac_part);
	else
		number = ft_strdup(frac_part);
	exp_after_rounding(&number, &exp, precision, int_size);
	if (exp <= -4 || exp > precision)
	{
		do_exp_rounding(&number, &exp, precision - 1);
		number = add_exp(exp, number, 1);
	}
	else
	{
		free(number);
		number = get_round_number(int_part, frac_part, precision - int_size);
		if (ft_strchr(number, '.'))
			del_last_zero(&number, ft_strlen(number));
	}
	return (number);
}

char	*get_number_shortest_rep(char *int_part, char *frac_part, int precision)
{
	int		exp;
	char	*number;
	int		int_size;

	exp = 0;
	int_size = ft_strlen(int_part);
	if (int_part[0] != '0')
		exp = ft_strlen(int_part) - 1;
	else
	{
		while (*frac_part == '0')
		{
			exp--;
			frac_part++;
		}
		if (*frac_part != 0)
			exp--;
		else
			exp = 0;
	}
	number = check_exp_for_format(exp, int_part, frac_part, precision);
	return (number);
}

char	*get_dtoa_shortest_rep(unsigned long long mant, short exp,
int precision)
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
	number = get_number_shortest_rep(int_part, frac_part, precision);
	free(int_part);
	free(frac_part);
	return (number);
}

char	*ft_dtoa_shortest_rep(double dbl, int precision)
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
		number = get_dtoa_shortest_rep(mant, exp, precision);
	if (sign == 1)
		number = add_chars_to_mall_str(number, "-", 'f');
	return (number);
}

/*void	test(double nbr)
{
	int precision = 99;
	char *str_g = ft_dtoa_shortest_rep(nbr, precision);
	char *str_f = ft_dtoa(nbr, 50, 0);
	char *str_e = ft_dtoa(nbr, 50, 1);
	printf("F : %s\nR : %.50f\nE : %s\nR : %.50e\nG : %s\nR : %.99g\n\n", str_f, nbr, str_e, nbr, str_g, nbr);
	free(str_g);
	free(str_f);
	free(str_e);
}

int main()
{
	test(999994.94);
	test(100000.0);
	double nbr;
	nbr = 0.0000000000000000000000000000000000000000000000001;
	test(nbr);
	test(19.99);
	test(99.999);
	test(0.25);
	test(-0.25);
	test(-42);
	test(INFINITY);
	test (-INFINITY);
	test(NAN);
	test(-NAN);
	test(222222222222222222222022222222222222.20);
	test(2);
	test(0);
	test(1);
	test(0.0000000000000086);
	test(0.000000000000000000000000000000000000000000000000000004);
	test(2.54);
	test(2.49);
	test(0.0);
	test(154.987456622358632);
	test(425896315587899);
	test(22222222228963214522222222222222222222.20);
	test(100000000000);
}*/
