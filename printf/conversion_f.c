/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:02:54 by smakni            #+#    #+#             */
/*   Updated: 2018/11/17 19:28:54 by smakni           ###   ########.fr       */
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

static	char	*int_part(double n, int precision, char c)
{
	if (precision != 0)
		return (ft_strjoin_free1(ft_itoa_lli(n), "."));
	else if (c > '4')
		return (ft_itoa_lli(n + 1));
	else
		return (ft_itoa_lli(n));
}

static	char	*int_part_bf(long double n, int precision, char c)
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

static	char	*floating_part(int precision, double n)
{
	char		*tmp;
	int			i;
	int			stop;

	if (n < 0)
		n = -n;
	if (!(tmp = ft_memalloc(1)))
		exit(-1);
	i = 1;
	stop = 0;
	while (stop < precision - 1)
	{
		n = (n - (long long)n) * ft_power(10, (i));
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n));
		stop += i;
	}
	if ((n = (n - (long long)n) * ft_power(10, (i))) > 4)
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n + 1));
	else
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n));
	return (tmp);
}

static	char	*floating_part_bf(int precision, long double n)
{
	char		*tmp;
	int			i;
	int			stop;

	if (n < 0)
		n = -n;
	if (!(tmp = ft_memalloc(1)))
		exit(-1);
	i = 1;
	stop = 0;
	while (stop < precision - 1)
	{
		n = (n - (long long)n) * ft_power(10, (i));
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n));
		stop += i;
	}
	if ((n = (n - (long long)n) * ft_power(10, (i))) > 4)
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n + 1));
	else
		tmp = ft_strjoin_2free(tmp, ft_itoa_lli(n));
	return (tmp);
}

char			*ft_itoa_f(t_format *arg, double n)
{
	char	*tmp;
	char	*tmp2;
	int		precision;

	tmp = NULL;
	precision = get_precision(arg);
	if (n == 0)
		return (f0(precision));
	tmp2 = floating_part(precision, n);		
	tmp = int_part(n, precision, tmp2[precision]);
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}

char			*ft_itoa_bf(t_format *arg, long double n)
{
	char		*tmp;
	char		*tmp2;
	int			precision;

	tmp = NULL;
	precision = get_precision(arg);
	if (n == 0)
		return (f0(precision));
	tmp2 = floating_part_bf(precision, n);		
	tmp = int_part_bf(n, precision, tmp2[precision]);
	tmp = ft_memjoin(tmp, tmp2, ft_strlen(tmp), precision);
	ft_strdel(&tmp2);
	return (tmp);
}
