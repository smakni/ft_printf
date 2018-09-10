/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/09/10 16:53:36 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_c(t_format *arg, va_list av)
{
	int				i;

	i = 0;
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
			if (arg->type == 'c')
				ft_putchar(va_arg(av, int));
			else
				ft_putchar(va_arg(av, wint_t));
			ft_putstr(arg->res);
		}
		else
		{
			ft_putstr(arg->res);
			if (arg->type == 'c')
				ft_putchar(va_arg(av, int));
			else
				ft_putchar(va_arg(av, wint_t));
		}
		return ;
	}
	arg->count = 1;
	if (arg->type == 'c')
		ft_putchar(va_arg(av, int));
		else
	ft_putchar(va_arg(av, wint_t));
}
