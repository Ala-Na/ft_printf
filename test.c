#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int i;
	int y;
	/*i = ft_printf("M :|%% *.5i 42 == |% *.5i|\n", 4, 42);
	y = printf("P :|%% *.5i 42 == |% *.5i|\n", 4, 42);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M:%23|\n");
	y = printf("P:%23|\n");
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M:%hh\n");
	y = printf("P:%hh\n");
	if (i != y)
		printf("error : %i should be %i\n", i, y);*/
	i = ft_printf("M:%5c|\n", '\0');
	y = printf("P:%5c|\n", '\0');
	if (i != y)
		printf("error : %i should be %i\n", i, y);

}
