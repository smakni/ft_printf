#include "ft_printf.h"

int		affStr(va_list av)
{
	ft_putstr(va_arg(av, char *));
	return true;
}

int		affCh(va_list av)
{
	char c;
	c = va_arg(av, int);
	ft_putchar(c);
	return true;
}

int 	affInt(va_list av)
{
	ft_putnbr(va_arg(av, int));
	return true;
}
