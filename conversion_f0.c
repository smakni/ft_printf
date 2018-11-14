#include "ft_printf.h"

static	char	*conversion_df(t_format *arg, char *nb, va_list av)
{
	double x;

	x = va_arg(av, double);
	nb = ft_itoa_bf(arg, x);
	return (nb);
}

static	char	*conversion_ldf(t_format *arg, char *nb, va_list av)
{
	long double x;

	x = va_arg(av, long double);
	nb = ft_itoa_bf(arg, x);
	return (nb);
}

char			*conversion_f(t_format *arg, char *nb, va_list av)
{

	if (ft_strchr(arg->str, 'L') != 0)
		nb = conversion_ldf(arg, nb, av);
	else
		nb = conversion_df(arg, nb, av);
	return (nb);
}


