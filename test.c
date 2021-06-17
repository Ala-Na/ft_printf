#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#define DBL_NAN    0x7FF0000000100000

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
	/*i = ft_printf("M:%5c|\n", '\0');
	y = printf("P:%5c|\n", '\0');
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M:%#05x|\n", 43);
	y = printf("P:%#05x|\n", 43);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: |%#-03.2x| |\n", 0);
	y = printf("P: |%#-03.2x| |\n", 0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %-5%|\n");
	y = printf("P: %-5%|\n");
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	double special;
	*((unsigned long *)(&special)) = DBL_NAN;
	i = ft_printf("M: |%f|\n", special);
	y = printf("P: |%f|\n", special);
	if (i != y)
		printf("error : %i should be %i\n", i, y);	
	i = ft_printf("M: % .7f|\n", special);
	y = printf("P: % .7f|\n", special);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.13g\n",        1.025978548534310421);
	y = printf("P: %.13g\n",        1.025978548534310421);
	if (i != y)
		printf("error : %i should be %i\n", i, y);	
	i = ft_printf("M: %.14g|\n",  9.999999999999990000);
	y = printf("P: %.14g|\n",  9.999999999999990000);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.15g|\n",        1.025978542436587568);
	y = printf("P: %.15g|\n",        1.025978542436587568);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.15g|\n",        1.025978548534310421);
	y = printf("P: %.15g|\n",        1.025978548534310421);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %+#-05.3g|\n", -0.0);
	y = printf("P: %+#-05.3g|\n", -0.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M:  %#g |\n", -0.1);
	y = printf("P:  %#g |\n", -0.1);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %+#-5.1g|\n", -7.3);
	y = printf("P: %+#-5.1g|\n", -7.3);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %+#-5.0g|\n", -7.3);
	y = printf("P: %+#-5.0g|\n", -7.3);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: % #-5.1g|\n", 7.3);
	y = printf("P: % #-5.1g|\n", 7.3);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %+6g\n", special);
	y = printf("P: %+6g\n", special);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.12e\n", -DBL_MIN);
	y = printf("P: %.12e\n", -DBL_MIN);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	char 		ch_pos_1 = 100, ch_neg_1 = -87;
	char	str_1[] = "hello world", str_2[] = "panda";
	char 	*str_3 = "this is a longer string";
	char	str_empty[] = "";
	static long long	ll_pos_1 = 22337203685477, ll_neg_1 = -22337203685477;
	i = ft_printf("M: %hhi%s%lli%s|\n", ch_pos_1, str_3, ll_neg_1, str_2);
	y = printf("P: %hhi%s%lli%s|\n", ch_pos_1, str_3, ll_neg_1, str_2);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.1g|\n", -9.999);
	y = printf("P: %.1g|\n", -9.999);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %.0f|\n", -9.999);
	y = printf("P: %.0f|\n", -9.999);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %5%|\n");
	y = printf("P: %5%|\n");
	if (i != y)
		printf("error : %i should be %i\n", i , y);
	i = ft_printf("M: %#0-8.5X|\n", 34);
	y = printf("P: %#0-8.5X|\n", 34);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %#0-8.5X|\n", 0);
	y = printf("P: %#0-8.5X|\n", 0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	*/i = ft_printf("M: no minus % #5.3g|\n", -0.0);
	y = printf("P: no minus % #5.3g|\n", -0.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: % #0-5.3f|\n", 0.0);
	y = printf("P: % #-05.3f|\n", 0.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: % #-5.4g|\n", 0.0);
	y = printf("P: % #-5.4g|\n", 0.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: % #-5.10g|\n", 13.0);
	y = printf("P: % #-5.10g|\n", 13.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);
	i = ft_printf("M: %#.1g|\n", 0.0);
	y = printf("P: %#.1g|\n", 0.0);
	if (i != y)
		printf("error : %i should be %i\n", i, y);

}
