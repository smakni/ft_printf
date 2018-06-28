/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:15:56 by smakni            #+#    #+#             */
/*   Updated: 2018/06/28 14:04:06 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_s(t_format *arg, va_list av)
{
	char 	*tmp;
	int		i;

	if (arg->precision == 0)
	{
		return ft_putstr(va_arg(av, char *));
	}
	tmp = ft_strdup(va_arg(av, char *));
	i = 0;
	while(tmp[i] && i < arg->precision)
		i++;
	tmp = ft_strsub_free(tmp, 0, i);
	//if (ft_strchr(arg->option, '0'))
	ft_putstr(arg->res);
}

void	conversion_c(t_format *arg, va_list av)
{
	int				i;

	i = 0;
	if (arg->width > 1) 
	{
		if (!(arg->res = ft_memalloc(arg->width)))
			return ;
		ft_memset(arg->res, ' ', arg->width - 1);
		ft_putstr(arg->res);
		ft_strdel(&(arg)->res);
	}
	ft_putchar(va_arg(av, int));
}
