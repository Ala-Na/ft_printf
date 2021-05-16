#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"
#include "libft_bonus.h"

int	main()
{
	int res1;
	int res2;
	
	//c
	res1 = ft_printf("1.%-c%-c%c*|\n", 1, '0', 0);
	res2 = printf("1.%-c%-c%c*|\n", 1, '0', 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("2.%c|\n", 0);
	res2 = printf("2.%c|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("3.0%c|\n", 0);
	res2 = printf("3.0%c|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("4. -%*c* -%-*c* |\n", -2, 0, 2, 0);
	res2 = printf("4. -%*c* -%-*c* |\n", -2, 0, 2, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("5. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	res2 = printf("5. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("6. -%*c* -%-*c* |\n", -1, 0, 1, 0);
	res2 = printf("6. -%*c* -%-*c* |\n", -1, 0, 1, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("7. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	res2 = printf("7. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("8. -%-2c* -%2c* |\n", 0, 0);
	res2 = printf("8. -%-2c* -%2c* |\n", 0, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	//p
	res1 = ft_printf("9. %10p %-10p |\n", 0, 0);
	res2 = printf("9. %10p %-10p |\n", 0, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	//s
	res1 = ft_printf("10. |%*.s| %.1s |\n", 10, "123", "4567");
	res2 = printf("10. |%*.s| %.1s |\n", 10, "123", "4567");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("11. |%*.0s| %.2s |\n", 10, "123", "4567");
	res2 = printf("11. |%*.0s| %.2s |\n", 10, "123", "4567");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("12. |%10.s| |%1.s| |\n", "123", "4567");
	res2 = printf("12. |%10.s| |%1.s| |\n", "123", "4567");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("13.|%s|\n", "");
	res2 = printf("13.|%s|\n", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("14.|%s %s|\n", "", "");
	res2 = printf("14.|%s %s|\n", "", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("15.| %s %s |\n", "", "");
	res2 = printf("15.| %s %s |\n", "", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("16.|%.s|\n", "");
	res2 = printf("16.|%.s|\n", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("17.|%.0s|\n", "");
	res2 = printf("17.|%.0s|\n", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("18.%.1s|\n", "");
	res2 = printf("18.%.1s|\n", "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("19. %4.2s %-4.2s |\n", "123", "4567");
	res2 = printf("19. %4.2s %-4.2s |\n", "123", "4567");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	//d i
	res1 = ft_printf("20. 0*%0-*.*d*0 0*%0*.*d*0 |\n", 2, 6, 102, 21, 10, -101);
	res2 = printf("20. 0*%0-*.*d*0 0*%0*.*d*0 |\n", 2, 6, 102, 21, 10, -101);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("21. --0*|%0*.0d|*0 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	res2 = printf("21. --0*|%0*.0d|*0 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
}
