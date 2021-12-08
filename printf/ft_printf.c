
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr("(null)", len);
	else
		while (s[i])
			ft_putchar(s[i++], len);
}

void	ft_putnbr(int n, int *len)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + 48, len);
	if (nb > 9)
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_puthex(unsigned int n, int *len)
{
	unsigned long nb;

	nb = n;
	// if (nb < 0)
	// {
	// 	ft_putchar('-', len);
	// 	nb *= -1;
	// }
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, len);
		if (nb > 9)
			ft_putchar((nb % 10) + 'a', len);
	}
	if (nb >= 16)
	{
		ft_puthex(nb / 16, len);
		ft_puthex(nb % 16, len);
	}
}

int	ft_check_arg(va_list ap, char c, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), len);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), len);
	if (c == 'd')
		ft_putnbr(va_arg(ap, int), len);
	if (c == 'x')
		ft_puthex(va_arg(ap, unsigned int), len);
	return (*len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_arg(ap, format[i], &len);
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	return (len);
}

// int	main(void)
// {
// 	char *s = "Hello this is ";
// 	char c = 'a';
// 	int	d = 1337;

// 	ft_printf("|%d|\n", ft_printf("%s ==> %d, ... %c :) check this %x", s, d, c, d));
// 	printf("|%d|\n", printf("%s ==> %d, ... %c :) check this %x", s, d, c, d));
// }