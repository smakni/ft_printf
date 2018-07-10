/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/07/10 14:34:21 by sabri            ###   ########.fr       */
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
		ft_putstr(arg->res);
		arg->count = arg->width;
		ft_strdel(&(arg)->res);
		ft_putchar(va_arg(av, int));
		return ;
	}
	arg->count = 1;
	ft_putchar(va_arg(av, int));
}
