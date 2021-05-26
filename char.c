#include <unistd.h>
#include <stdio.h>
#include <wchar.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	main()
{
	int i =  ft_putchar(u'ʰ');
	printf("%i\n", i);
}
