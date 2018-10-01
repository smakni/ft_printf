/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/09/14 16:35:54 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_c(wint_t c)
{
	if (c <= 127)
        return (1);
    else if (c <= 2047 && MB_CUR_MAX >=1)
		return (2);
	else if ((c <= 55295 || (c >= 57344 && c <= 64975) 
			|| (c >= 65008 && c <= 65533)) && MB_CUR_MAX >= 2)
		return (3);
    else if (((c >= 65536 && c <= 131069) || (c >= 131072 && c <= 196605)
	    	|| (c >= 917504 && c <= 983037)
			|| (c >= 983040 && c <= 1048573)
			|| (c >= 1048576 && c <= 1114109)) && MB_CUR_MAX >= 3)
		return (4);
    else
		return (-1);
}

static void	conversion_c1(t_format *arg, wint_t c)
{
	ft_putchar_printf(c, arg);
	if ((arg->res = ft_memalloc(arg->width - arg->count - 1)) == NULL)
			return ;
	ft_memset(arg->res, ' ', arg->width - arg->count - 1);
	if (arg->count < arg->width)
		arg->count = arg->width;
	else
		arg->count += arg->width;
	ft_putstr_printf(arg->res, arg);

}

static void	conversion_c2(t_format *arg, wint_t c, int check)
{
	if ((arg->res = ft_memalloc(arg->width - check + 1)) == NULL)
			return ;
	ft_memset(arg->res, ' ', arg->width - check);
	ft_putstr_printf(arg->res, arg);
	arg->count = arg->width - check + 1; 
	ft_putchar_printf(c, arg);
}

void	conversion_c(t_format *arg, va_list av)
{
	wint_t 	c;
	int		check;

	c = va_arg(av, wint_t);
	if ((check = check_c(c)) == -1)
	{
		arg->check = -1;
		return ;
	}
	if (arg->width > 1) 
	{
		if (ft_strchr(arg->option, '-') != 0)
			return (conversion_c1(arg, c));
		else
			return (conversion_c2(arg, c, check));
	}
	arg->count = 1;
	ft_putchar_printf(c, arg);
}
