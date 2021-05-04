#include "ft_printf.h"

char	*del_front_zero(char *to_add, int approx_size)
{
	int	nbr_zero;
	int	i;
	int	y;
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
	if (!(tmp = malloc(sizeof(*to_add) * (approx_size - nbr_zero + 1))))
		return (NULL);
	while (to_add[i] != 0)
		tmp[y++] = to_add[i++];
	tmp[y] = 0;
	free(to_add);
	return (tmp);
}

char	*apply_ptwo(short exp)
{
	char	*to_add;
	int	approx_size;
	int	curr_exp;
	int	i;
	int	rem;
	char 	tmp;

	i = 0;
	curr_exp = 1;
	approx_size = exp / 3;
	if (!(to_add = malloc(sizeof(*to_add) * (approx_size + 1))))
		return (NULL);
	while (i < approx_size)
		to_add[i++] = '0';
	to_add[i--] =  0;
	to_add[i] = '2';
	while (curr_exp < exp)
	{
		rem = 0;
		i = approx_size - 1;
		while (i >= 0)
		{
			tmp = (((to_add[i] - '0') * 2) % 10) + rem;
			rem = (((to_add[i] - '0') * 2) - (((to_add[i] - '0') * 2) % 10)) / 10;
			to_add[i--] = tmp + '0';
		}
		curr_exp++;
	}
	to_add = del_front_zero(to_add, approx_size);
	return (to_add);
}

