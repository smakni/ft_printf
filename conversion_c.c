/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/09/13 16:52:35 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_c(t_format *arg, va_list av)
{
	if (arg->width > 1) 
	{
		if (!(arg->res = ft_memalloc(arg->width)))
			return ;
		if (ft_strchr(arg->option, '0') != 0)
			ft_memset(arg->res, '0', arg->width - 1);
		else
			ft_memset(arg->res, ' ', arg->width - 1);
		arg->count = arg->width;
		if (ft_strchr(arg->option, '-') != 0)
		{
			if (arg->type == 'c' && (ft_strcmp(arg->size, "l") != 0))
				ft_putchar_printf(va_arg(av, int), arg);
			else
				ft_putchar_printf(va_arg(av, wint_t), arg);
			ft_putstr(arg->res);
		}
		else
		{
			ft_putstr(arg->res);
			if (arg->type == 'c' && (ft_strcmp(arg->size, "l") != 0))
				ft_putchar_printf(va_arg(av, int), arg);
			else
				ft_putchar_printf(va_arg(av, wint_t), arg);
		}
		return ;
	}
	arg->count = 1;
	if (arg->type == 'c' && (ft_strcmp(arg->size, "l") != 0))
		ft_putchar_printf(va_arg(av, int), arg);
	else
		ft_putchar_printf(va_arg(av, wint_t), arg);
}
