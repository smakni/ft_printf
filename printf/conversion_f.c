/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:02:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/17 15:23:38 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		get_precision(t_format *arg)
{
	if (ft_strchr(arg->str, '.') == 0)
		return (6);
	else
		return (arg->precision);
}

static	char	*around(double n, int precision, char c)
{
	if (precision != 0)
		return (ft_strjoin_free1(ft_itoa_lli(n), "."));
	else if (c > '4')
		return (ft_itoa_lli(n + 1));
	else
		return (ft_itoa_lli(n));
}

static	char	*around_bf(long double n, int precision, char c)
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

char			*ft_itoa_f(t_format *arg, double n)
{
	char	*tmp;
	char	*tmp2;
	int		precision;
	int		s;

	tmp = NULL;
	s = 1;
	precision = get_precision(arg);
	if (n == 0)
		return (f0(precision));
	if (n < 0)
		s = -1;
	tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision + 1)));
	tmp = around(n, precision, tmp2[precision]);
	if (tmp2[precision] > '4')
	{
		ft_strdel(&tmp2);
		tmp2 = ft_itoa_lli((n - (long long)n) * s *
								ft_power(10, (precision)) + 1);
	}
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}

char			*ft_itoa_bf(t_format *arg, long double n)
{
	char		*tmp;
	char		*tmp2;
	int			precision;
	int			s;

	tmp = NULL;
	s = 1;
	precision = get_precision(arg);
	if (n == 0)
		return (f0(precision));
	if (n < 0)
		s = -1;
	tmp2 = ft_itoa_lli((n - (long long)n) * s * ft_power(10, (precision + 1)));
	tmp = around_bf(n, precision, tmp2[precision]);
	if (tmp2[precision] > '4')
	{
		ft_strdel(&tmp2);
		tmp2 = ft_itoa_lli((n - (long long)n) * s *
								ft_power(10, (precision)) + 1);
	}
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}
