/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:53:06 by elanna            #+#    #+#             */
/*   Updated: 2021/05/05 20:53:48 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_chars_to_mall_str(char *mall_str, const char *cst,
char front_or_end)
{
	char *tmp;

	if (front_or_end == 'f')
		tmp = ft_strjoin(cst, mall_str);
	else
		tmp = ft_strjoin(mall_str, cst);
	free(mall_str);
	return (tmp);
}

void	stock_fill(char **stock_part, char *to_add, int s_part, int s_add)
{
	int ret;

	ret = 0;
	while (s_part >= 0 && s_add >= 0)
	{
		(*stock_part)[s_part] += to_add[s_add--] - '0' + ret;
		ret = 0;
		if ((*stock_part)[s_part--] > '9')
		{
			(*stock_part)[s_part + 1] -= 10;
			ret = 1;
		}
	}
	while (ret != 0 && s_part >= 0)
	{
		(*stock_part)[s_part] += 1;
		ret = 0;
		if ((*stock_part)[s_part--] > '9' && s_part != 0)
		{
			(*stock_part)[s_part + 1] -= 10;
			ret = 1;
		}
	}
	if (ret != 0 && s_part == -1)
		*stock_part = add_chars_to_mall_str(*stock_part, "1", 'f');
}

char	*stock_init(char *stock_part, char *to_add, char int_or_frac)
{
	int	ret;
	int	size_part;
	int	size_add;

	if (stock_part == NULL)
		return (to_add);
	else if (to_add == NULL)
		return (NULL);
	size_part = ft_strlen(stock_part) - 1;
	size_add = ft_strlen(to_add) - 1;
	while (size_part < size_add)
	{
		stock_part = add_chars_to_mall_str(stock_part, "0", int_or_frac);
		size_part++;
	}
	if (stock_part == NULL)
	{
		free(to_add);
		return (NULL);
	}
	stock_fill(&stock_part, to_add, size_part, size_add);
	free(to_add);
	return (stock_part);
}

char	*apply_dtwo_pten(unsigned int i)
{
	char			*to_add;
	char			tmp;
	unsigned int	y;
	unsigned int	z;
	char			rem;

	y = 1;
	if (!(to_add = malloc(sizeof(*to_add) * (i + 1))))
		return (NULL);
	to_add[0] = '5';
	to_add[i] = 0;
	while (y < i)
	{
		to_add[y++] = '0';
		z = 0;
		rem = 0;
		while (z <= (y - 1))
		{
			tmp = (to_add[z] + '0') / 2 + (rem * 5);
			rem = (to_add[z] - '0') % 2;
			to_add[z++] = tmp;
		}
	}
	return (to_add);
}

unsigned long long	convert_mant_to_frac(unsigned long long mant, short exp,
unsigned int *i)
{
	*i = 1;
	if (exp > 0)
		return (mant << (exp + 1));
	else if (exp == 0)
		return (mant << 1);
	*i = (unsigned int)(-exp);
	return (mant);
}

char	*get_frac_part(unsigned long long mant, short exp)
{
	unsigned long long	frac_part;
	char				*to_add;
	unsigned int		i;
	char				*stock_frac;

	stock_frac = NULL;
	frac_part = convert_mant_to_frac(mant, exp, &i);
	if (frac_part == 0 || exp > 63)
		return (ft_strdup("0"));
	while (frac_part != 0)
	{
		if (((frac_part >> 63) & 1) == 0)
		{
			frac_part = frac_part << 1;
			i++;
			continue ;
		}
		to_add = apply_dtwo_pten(i);
		frac_part = frac_part << 1;
		stock_frac = stock_init(stock_frac, to_add, 'e');
		i++;
	}
	return (stock_frac);
}

char	*del_front_zero(char *to_add, int approx_size)
{
	int		nbr_zero;
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	y = 0;
	nbr_zero = 0;
	while (to_add[i] == '0')
	{
		nbr_zero++;
		i++;
	}
	if (nbr_zero == 0)
		return (to_add);
	if (!(tmp = malloc(sizeof(*tmp) * (approx_size - nbr_zero + 1))))
		return (NULL);
	while (to_add[i] != 0)
		tmp[y++] = to_add[i++];
	tmp[y] = 0;
	free(to_add);
	return (tmp);
}

void	apply_ptwo_fill(char **to_add, int approx_size)
{
	char	tmp;
	char	rem;
	int		i;

	rem = 0;
	i = approx_size - 1;
	while (i >= 0)
	{
		tmp = ((((*to_add)[i] - '0') * 2) % 10) + rem;
		rem = (((*to_add)[i] - '0') * 2) - ((((*to_add)[i] - '0') * 2) % 10);
		rem /= 10;
		(*to_add)[i--] = tmp + '0';
	}
}

void	apply_ptwo_init(short exp, char **to_add)
{
	int	approx_size;
	int	curr_exp;
	int	i;

	i = 0;
	curr_exp = 1;
	approx_size = exp / 3 + 1;
	if (!(*to_add = malloc(sizeof(**to_add) * (approx_size + 1))))
		return ;
	while (i < approx_size)
		(*to_add)[i++] = '0';
	(*to_add)[i--] = 0;
	(*to_add)[i] = '2';
	while (curr_exp < exp)
	{
		apply_ptwo_fill(to_add, approx_size);
		curr_exp++;
	}
	*to_add = del_front_zero(*to_add, approx_size);
}

char	*get_big_int(unsigned long long int_part, short exp)
{
	char	*to_add;
	short	i;
	char	*stock_big_int;

	i = exp - 52;
	stock_big_int = NULL;
	to_add = NULL;
	while (int_part != 0)
	{
		if ((int_part & 1) == 0)
		{
			int_part = int_part >> 1;
			i++;
			continue ;
		}
		apply_ptwo_init(i, &to_add);
		int_part = int_part >> 1;
		stock_big_int = stock_init(stock_big_int, to_add, 'f');
		i++;
	}
	return (stock_big_int);
}

char	*get_int_part(unsigned long long mant, short exp)
{
	unsigned long long	int_part;

	int_part = 0;
	if (exp == 0)
		int_part = 1;
	else if (exp > 0 && exp <= 63)
	{
		int_part = mant >> (63 - exp);
		int_part = ft_bintodec(int_part, 0);
	}
	else if (exp > 63)
	{
		int_part = mant >> 11;
		return (get_big_int(int_part, exp));
	}
	return (ft_ullitoa(int_part));
}

void	do_rounding(char **number, char *frac_part,
unsigned i, unsigned size)
{
	while (i < size)
	{
		if (*frac_part)
			(*number)[i++] = *frac_part++;
		else
			(*number)[i++] = '0';
	}
	if (*frac_part > '5' && *frac_part <= '9')
	{
		(*number)[--i] += 1;
		while ((*number)[i] > '9')
		{
			(*number)[i] = '0';
			if (i > 0 && (*number)[--i] == '.')
				--i;
			if ((*number)[i] == '9' && i == 0)
			{
				(*number)[i] = '0';
				*number = add_chars_to_mall_str(*number, "1", 'f');
			}
			else
				(*number)[i] += 1;
		}
	}
}

char	*get_round_number(char *int_part, char *frac_part, int precision)
{
	char			*number;
	unsigned int	size;
	unsigned int	i;

	if (precision == 0)
		size = ft_strlen(int_part);
	else
		size = ft_strlen(int_part) + precision + 1;
	if (!(number = malloc(sizeof(*number) * (size + 1))))
		return (NULL);
	number[size] = 0;
	i = 0;
	while (i < size && *int_part)
	{
		number[i++] = *int_part++;
	}
	number[i] = 0;
	if (i < size - 1)
		number[i++] = '.';
	do_rounding(&number, frac_part, i, size);
	return (number);
}

char	*get_dtoa_number(unsigned long long mant, short exp, int precision,
int show_exp)
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
	if (show_exp == 0)
		number = get_round_number(int_part, frac_part, precision);
	else
		number = get_round_exp_number(int_part, frac_part, precision);
	free(int_part);
	free(frac_part);
	return (number);
}

char	*ft_dtoa(double dbl, int precision, int show_exp)
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
		number = get_dtoa_number(mant, exp, precision, show_exp);
	if (sign == 1)
		number = add_chars_to_mall_str(number, "-", 'f');
	return (number);
}

/*void	test(double dbl)
{
	char *str;
	printf("printf : %.1000f\n", dbl);
	str = ft_dtoa(dbl, 1000);
	printf("mine   : %s\n", str);
	free(str);
	str = ft_dtoa(dbl, 6);
	printf("mine   : %s\n", str);
	free(str);
	printf("printf : %f\n", dbl);
	printf("printf : %.1f\n", dbl);
	str = ft_dtoa(dbl, 1);
	printf("mine   : %s\n", str);
	free(str);
	printf("\n");
}

int main()
{
	double nbr;
	nbr = 0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
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

}*/
