#include <stdio.h>
#include <limits.h>
#include "libft.h"
#include "libft_bonus.h"
#include "ft_printf_bonus.h"
#define ULONG_MIN ((unsigned long int)0)

int	main()
{
	int res1;
	int res2;
	

	/*printf("c :\n\n");
	res1 = ft_printf("Mine 1.%-c%-c%c*|\n", 1, '0', 0);
	res2 = printf("Prin 1.%-c%-c%c*|\n", 1, '0', 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("2.%10c|\n", '0');
	res2 = printf("2.%10c|\n", '0');
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
	res1 = ft_printf("6m. -%*c* -%-*c* |\n", -1, 0, 1, 0);
	res2 = printf("6p. -%*c* -%-*c* |\n", -1, 0, 1, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("7m. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	res2 = printf("7p. -%-*c* -%-*c* |\n", 2, 0, -2, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("8m. -%-3c* -%2c* |\n", 0, 0);
	res2 = printf("8p. -%-3c* -%2c* |\n", 0, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("Mine :%%*.s%c%%*.s*%ss%%*.s|\n", '2', "");
	res2 = printf("Prin :%%*.s%c%%*.s*%ss%%*.s|\n", '2', "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);

	printf("\np :\n\n");
	res1 = ft_printf("9. %10p %-10p |\n", 0, 0);
	res2 = printf("9. %10p %-10p |\n", 0, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	
	printf("\ns :\n\n");
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
	
	printf("\nd/i :\n\n");
	res1 = ft_printf("20. 0*%0-*.*d*0 0*%0*.*d*0 |\n", 2, 6, 102, 21, 10, -101);
	res2 = printf("20. 0*%0-*.*d*0 0*%0*.*d*0 |\n", 2, 6, 102, 21, 10, -101);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("21. --0*|%0*.0d|*0 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	res2 = printf("21. --0*|%0*.0d|*0 0*%0*.10d*0-- |\n", -2, 0, 21, 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);

	printf("\nu :\n\n");
	res1 = ft_printf("22. %.u |\n", 0);
	res2 = printf("22. %.u |\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("23. --0*%0*.0u*0 0*%0*.10u*0-- |\n", -2, 0, 21, 1);
	res2 = printf("23. --0*%0*.0u*0 0*%0*.10u*0-- |\n", -2, 0, 21, 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("24. %.u |\n", 0);
	res2 = printf("24. %.u |\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("25.%09.0u|\n", UINT_MAX + 1);
	res2 = printf("25.%09.0u|\n", UINT_MAX + 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("26.%010.0u|\n", UINT_MAX + 1);
	res2 = printf("26.%010.0u|\n", UINT_MAX + 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("27.%011.0u|\n", UINT_MAX + 1);
	res2 = printf("27.%011.0u|\n", UINT_MAX + 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("28.%.0u|\n", 0);
	res2 = printf("28.%.0u|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("29.%1.u|\n", 0);
	res2 = printf("29.%1.u|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("30.%2.u|\n", 0);
	res2 = printf("30.%2.u|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("31.%3.u|\n", 0);
	res2 = printf("31.%3.u|\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);

	printf("\nmix :\n\n");
	res1 = ft_printf("32. a%c%%c%%s%%p%%d%%i%%u%%x%%X%% |\n", 0);
	res2 = printf("32. a%c%%c%%s%%p%%d%%i%%u%%x%%X%% |\n", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("33. a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p|\n", 0, (void *)42);
	res2 = printf("33. a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%p|\n", 0, (void *)42);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("34. a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s|\n", 0, "");
	res2 = printf("34. a%c%%c%%s%%p%%d%%i%%u%%x%%X%%p%s|\n", 0, "");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("35.%%*.s%c%%*.s*%ss%%*.s|\n", 0, "5");
	res2 = printf("35.%%*.s%c%%*.s*%ss%%*.s|\n", 0, "5");
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("36.%%%s%c%%c|\n", "", 0);
	res2 = printf("36.%%%s%c%%c|\n", "", 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("37. %% %% %% %% %c %%cc%%cc%%%c |\n", -1, 0);
	res2 = printf("37. %% %% %% %% %c %%cc%%cc%%%c |\n", -1, 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);

	printf("\n n :\n\n");
	int a = 0;
	int b = 0;
	res1 = ft_printf("38. %s%c42%n|\n", "12345", 0, &a);
	res2 = printf("38. %s%c42%n|\n", "12345", 0, &b);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	if (a != b)
		printf("Error n : %i supposed to be %i\n", res1, res2);
	a = 0;
	b = 0;
	res1 = ft_printf("39. %s%c%i42%n|\n", "12345", 0, 42, &a);
	res2 = printf("39. %s%c%i42%n|\n", "12345", 0, 42, &b);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	if (a != b)
		printf("Error n : %i supposed to be %i\n", res1, res2);


	printf("\nf :\n\n");
	res1 = ft_printf("40. %07.f %08.1f %09.2f |\n", 0.0, -1.0, 42.0);
	res2 = printf("40. %07.f %08.1f %09.2f |\n", 0.0, -1.0, 42.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("41. %02.f %02.1f %02.2f |\n", 0.0, -1.0, 42.0);
	res2 = printf("41. %02.f %02.1f %02.2f |\n", 0.0, -1.0, 42.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("42. %06.3f %06.3f %06.3f i|\n", 0.0, -1.0, 42.0);
	res2 = printf("42. %06.3f %06.3f %06.3f i|\n", 0.0, -1.0, 42.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("43. %f %f |\n", LONG_MIN * 1.0, LONG_MAX * 1.0);
	res2 = printf("43. %f %f |\n", LONG_MIN * 1.0, LONG_MAX * 1.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("43. %f %f |\n", LONG_MIN + 0.5, LONG_MAX + 0.7);
	res2 = printf("43. %f %f |\n", LONG_MIN + 0.5, LONG_MAX + 0.7);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("44.%.0f|\n", 1.5);
	res2 = printf("44.%.0f|\n", 1.5);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("45.%.0f|\n", -3.5);
	res2 = printf("45.%.0f|\n", -3.5);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("46.%.0f|\n", 3.5);
	res2 = printf("46.%.0f|\n", 3.5);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("47. %020.20f |\n", 1.0 / 0);
	res2 = printf("47. %020.20f |\n", 1.0 / 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("48.%.0f|\n|\n", 1.5);
	res2 = printf("48.%.0f|\n|\n", 1.5);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("49. %020.20f |\n", 0.0 / 0);
	res2 = printf("49. %020.20f |\n", 0.0 / 0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("50. %.16f %.16f |\n", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	res2 = printf("50. %.16f %.16f |\n", 0.01234567890123456789012345678901, -0.01234567890123456789012345678901);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	
	printf("\ng :\n\n");
	res1 = ft_printf("51. %g |\n", 1.0 / 10000);
	res2 = printf("51. %g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("52. %.g |\n", 1.0 / 10000);
	res2 = printf("52. %.g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("53. %.1g |\n", 1.0 / 10000);
	res2 = printf("53. %.1g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("54. %.2g |\n", 1.0 / 10000);
	res2 = printf("54. %.2g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("55. %.16g |\n", 1.0 / 10000);
	res2 = printf("55. %.16g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("56. %-g |\n", 1.0 / 10000);
	res2 = printf("56. %-g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("57. %-g |\n", 1.0 / 10000);
	res2 = printf("57. %-g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("58. %-.1g |\n", 1.0 / 10000);
	res2 = printf("58. %-.1g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("59. %-.2g |\n", 1.0 / 10000);
	res2 = printf("59. %-.2g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("60. %-.16g |\n", 1.0 / 10000);
	res2 = printf("60. %-.16g |\n", 1.0 / 10000);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("61. %08.2g |\n", 420.0);
	res2 = printf("61. %08.2g |\n", 420.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("62. %08.2g |\n", -420.0);
	res2 = printf("62. %08.2g |\n", -420.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("63. %09.2g |\n", -420.0);
	res2 = printf("63. %09.2g |\n", -420.0);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);

	*/printf("\nl :\n\n");
	res1 = ft_printf("64. %lx |\n", ULONG_MAX);
	res2 = printf("64. %lx |\n", ULONG_MAX);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("65. %lx |\n", ULONG_MIN - 1);
	res2 = printf("65. %lx |\n", ULONG_MIN - 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("66. %lX |\n", ULONG_MAX);
	res2 = printf("66. %lX |\n", ULONG_MAX);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("67. %lX |\n", ULONG_MIN - 1);
	res2 = printf("67. %lX |\n", ULONG_MIN - 1);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("69. %lc |\n", u'ƀ');
	res2 = printf("69. %lc |\n", u'ƀ');
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("70. %lc |\n", u'ɏ');
	res2 = printf("70. %lc |\n", u'ɏ');
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	res1 = ft_printf("71. %lc |\n", u'ɐ');
	res2 = printf("71. %lc |\n", u'ɐ');
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);
	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	res1 = ft_printf("72. %ls |\n", s);
	res2 = printf("72. %ls |\n", s);
	if (res1 != res2)
		printf("Error : %i supposed to be %i\n", res1, res2);/*
*/}
