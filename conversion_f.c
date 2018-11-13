/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:02:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/13 19:22:37 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*around(double n, int precision ,char c)
{
	if (n == 0)
		return (ft_strdup("0.00000"));
	else if (precision != 0)
		return (ft_strjoin_free1(ft_itoa_lli(n), "."));
	else if (c > '4')
		return (ft_itoa_lli(n + 1));
	else
		return (ft_itoa_lli(n));
}

static	char	*ft_itoa_f(t_format *arg, va_list av)
{
	char	*tmp;
	char	*tmp2;
	int		precision;
	double	n;
	int		s;

	n = va_arg(av, double);
	tmp = NULL;
	s = 1;
	if (ft_strchr(arg->str, '.') == 0)
		precision = 6;
	else
		precision = arg->precision;
	if (n < 0)
		s = -1;
	tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision + 1)));
	tmp = around(n, precision, tmp2[precision]);
	if (tmp2[precision] > '4')
	{
		ft_strdel(&tmp2);
		tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision)) + 1);
	}
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}

static	char	*around_bf(long double n, int precision ,char c)
{
	if (n == 0)
		return (ft_strdup("0.00000"));
	else if (precision != 0)
		return (ft_strjoin_free1(ft_itoa_lli(n), "."));
	else if (c > '4')
		return (ft_itoa_lli(n + 1));
	else
		return (ft_itoa_lli(n));
}

static	char	*ft_itoa_bf(t_format *arg, va_list av)
{
	char		*tmp;
	char		*tmp2;
	int			precision;
	long double	n;
	int			s;

	n = va_arg(av, long double);
	tmp = NULL;
	s = 1;
	if (ft_strchr(arg->str, '.') == 0)
		precision = 6;
	else
		precision = arg->precision;
	if (n < 0)
		s = -1;
	tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision + 1)));
	tmp = around_bf(n, precision, tmp2[precision]);
	if (tmp2[precision] > '4')
	{
		ft_strdel(&tmp2);
		tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision)) + 1);
	}
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}

char			*conversion_f(t_format *arg, va_list av)
{
	if (ft_strchr(arg->str, 'L') != 0)
		return (ft_itoa_bf(arg, av));
	else
		return (ft_itoa_f(arg, av));
}
