/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/10/18 15:20:31 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_c(t_format *arg, wchar_t c)
{
	if (c <= 127)
		return (1);
	else if ((arg->type == 'c' && ft_strcmp(arg->size, "l") == 0)
				|| arg->type == 'C')
	{
    	 if (c <= 2047 && MB_CUR_MAX >=2)
			return (2);
		else if ((c <= 55295 || (c >= 57344 && c <= 64975) 
				|| (c >= 65008 && c <= 65533)) && MB_CUR_MAX >= 3)
			return (3);
   		 else if (((c >= 65536 && c <= 131069) || (c >= 131072 && c <= 196605)
		    	|| (c >= 917504 && c <= 983037)
				|| (c >= 983040 && c <= 1048573)
				|| (c >= 1048576 && c <= 1114109)) && MB_CUR_MAX >= 4)
			return (4);
	}
	return (1);
}

static int	check_error(wchar_t c)
{
		if ((c > 55295 && c < 57344) ||  c > 1114111)
					return (-1);
			return (0);
}

static void	conversion_c1(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check)) == NULL)
			return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res = ft_memjoin(arg->res, tmp, check, (arg->width - check)); 
}
static void	conversion_c2(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check + 1)) == NULL)
			return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res = ft_memjoin(tmp, arg->res, (arg->width - check), check);
	
}

void	conversion_c(t_format *arg, va_list av)
{
	wchar_t 	c;
	int			check;

	c = va_arg(av, wchar_t);
	if ((arg->check = check_error(c)) == -1)
		return ;
	arg->res = ft_memalloc(check = check_c(arg, c));
	ft_putstr("check = ");
	ft_putnbr(check);
	arg->res = ft_strdup(ft_putchar_printf(c, arg->res, check));
	if (arg->width > 1) 
	{
		if (ft_strchr(arg->option, '-') != 0)
			conversion_c1(arg, check);
		else
			conversion_c2(arg, check);
		arg->count = arg->width;
	}
	else
		arg->count = check;
}
