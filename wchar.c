//#include "libft.h"
//#include "ft_printf.h"
#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_print_bin_rep(size_t const size, void const *ptr)
{
	unsigned char	*byte;
	unsigned char	bit;
	int				i;
	int				j;

	byte = (unsigned char *)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			bit = (byte[i] >> j) & 1;
			ft_putnbr_fd(bit, 1);
			j--;
		}
		ft_putchar_fd(' ', 1);
		i--;
	}
	ft_putchar_fd(' ', 1);
	ft_putchar_fd('\n', 1);
}


size_t	ft_wcrtomb(char *s, wchar_t wc, mbstate_t *ps)
{
	size_t	i;

	i = 0;
	if (!s)
		return (1);
	if (s && (unsigned)wc < 0x80)
		s[i++] = wc;
	else if (s && (unsigned)wc < 0x800)
		s[i++] = (wc >> 6) & 0x1f | 0xc0;
	else if (s && (unsigned)wc < 0x10000)
		s[i++] = (wc >> 12) & 0x0f | 0xe0;
	else if (s && (unsigned)wc < 0x110000)
		s[i++] = (wc >> 18) & 0x07 | 0xf0;
	else if (s)
		return (-1);
	if (s && (unsigned)wc >= 0x10000)
		s[i++] = (wc >> 12) & 0x3f | 0x80;
	if (s && (unsigned)wc >= 0x800)
		s[i++] = (wc >> 6) & 0x3f | 0x80;
	if (s && (unsigned)wc >= 0x80)
		s[i++] = wc & 0x3f | 0x80;
	return (i);
}


int	ft_putwstr_fd(wchar_t *w_str, int fd)
{
	mbstate_t	ps;
	size_t		nbr_bytes;
	int		res;
	char		to_print;
	
	nbr_bytes = 0;
	res = 0;
	to_print = 0;
	memset(&ps, 0, sizeof(ps));
	while (w_str && nbr_bytes != -1 && *w_str)
	{
		nbr_bytes = ft_wcrtomb(&to_print, *w_str, &ps);
		write(fd, &to_print, nbr_bytes);
		*w_str++;
		res++;
	}
	if (nbr_bytes == -1)
		return (-1);
	return (res);
}


void print_wide(const wchar_t* wstr)
{
	printf("inside print wide\n");
	mbstate_t state;
	//memset(&state, 0, sizeof state);
	char mb[MB_CUR_MAX+1];
	for(;*wstr; ++wstr) {
		int ret = ft_wcrtomb(mb, *wstr, &state);
		mb[ret] = '\0';
		printf("multibyte char %s is %d bytes\n", mb, ret);
	}
}

int main()
{
	setbuf(stdout, NULL);
	//setlocale(LC_ALL, "en_US.UTF-8");
	wchar_t msg[] = L"안녕하세요.";
	printf("%d\n", printf("%lc\n", msg[0]));
	printf("%d\n", printf("%ls 끝.\n",msg));
	ft_putwstr_fd(msg, 1);
	ft_putwstr_fd(NULL, 1);

	size_t      sizeOfCovertion = 0;
	mbstate_t   mbstate;
	char        mbStr = 0;
	wchar_t*    wcStr = L"안녕";

	memset(&mbstate, 0, sizeof(mbstate));

	sizeOfCovertion = ft_wcrtomb(&mbStr, *wcStr, &mbstate);
	printf("size is %lu\n", sizeOfCovertion);
	if (sizeOfCovertion > 0)
	{
		printf("The corresponding wide character \"");
		wprintf(L"%s\"", wcStr);
		printf(" was converted to the \"%c\" ", mbStr);
		printf("multibyte character.\n");
	}
	else
	{
		printf("No corresponding multibyte character "
				"was found.\n");
	}

	//ft_printf("%d\n", ft_printf("%lc\n", msg[0]));
	//ft_printf("%d\n", ft_printf("%ls 끝.\n",msg));
}
