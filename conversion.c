/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:15:56 by smakni            #+#    #+#             */
/*   Updated: 2018/06/25 23:12:10 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_s(t_format *arg, va_list av)
{
	char 	*tmp;
	int		i;

	if (arg->precision == -1)
	{
		return ft_putstr(va_arg(av, char *));
	}
	tmp = ft_strdup(va_arg(av, char *));
	i = 0;
	while(tmp[i] && i < arg->precision)
		i++;
	arg->res = ft_strsub_free(tmp, 0, i);
	ft_putstr(arg->res);
}

void	conversion_c(t_format *arg, va_list av)
{
	int				i;

	i = 0;
	while (arg->str[i] != arg->type)
	{	
		if(arg->str[i] <= '0' || arg->str[i] > '9')
			return ;
		i++;
	}
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
