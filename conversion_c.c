/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/10/17 18:10:45 by smakni           ###   ########.fr       */
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

static void	conversion_c1(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check)) == NULL)
			return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res = ft_strjoin(arg->res, tmp); 
}
static void	conversion_c2(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check + 1)) == NULL)
			return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res= ft_strjoin(tmp, arg->res);
	
}

void	conversion_c(t_format *arg, va_list av)
{
	wchar_t 	c;
	char		*str;
	int			check;

	c = va_arg(av, wchar_t);
	if (c == '\0')
		arg->count += 1;
	if ((check = check_c(arg, c)) != -1)
		str = ft_memalloc(check);
	else
		return ;
	arg->res = ft_strdup(ft_putchar_printf(c, str, check));
	if (arg->width > 1) 
	{
		if (ft_strchr(arg->option, '-') != 0)
			conversion_c1(arg, check);
		else
			conversion_c2(arg, check);
	}
	arg->count += ft_strlen(arg->res);
}
