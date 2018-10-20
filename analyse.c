/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:45:05 by sabri             #+#    #+#             */
/*   Updated: 2018/10/20 16:19:16 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyse(t_format *arg)
{
	arg->len = ft_strlen(arg->str);
	arg->option = check_option(arg->str);
	arg->width = check_widht(arg->str);
	arg->precision = check_precision(arg->str);
	arg->size = check_size(arg->str);
}

void 	ft_conversion(t_format *arg, va_list av)
{
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i' 
			|| arg->type == 'u' || arg->type == 'U'
			|| arg->type == 'o' || arg->type == 'O'
			|| arg->type == 'x' || arg->type == 'X')
		conversion_d(arg, av);
	else if (arg->type == 'c' || arg->type == 'C')
		conversion_c(arg, av);
	else if (arg->type == 's' || arg->type == 'S')
		conversion_s(arg, av);
	else if (arg->type == 'p')
		conversion_p(arg, av);
	else if (arg->type == '%')
		conversion_0(arg);
	return ;
}
/*
void	ft_aff_param(t_format *arg)
{
	ft_putstr("\n--------\n");
	ft_putstr("ft_analyse = ");
	ft_putstr(arg->str);
	ft_putstr("\n");
	ft_putstr("type = ");
	ft_putchar(arg->type);
	ft_putstr("\n");
	ft_putstr("len = ");
	ft_putnbr(arg->len);
	ft_putstr("\n");
	ft_putstr("option = ");
	ft_putstr(arg->option);
	ft_putstr("\n");
	ft_putstr("width = ");
	ft_putnbr(arg->width);
	ft_putstr("\n");
	ft_putstr("precision = ");
	ft_putnbr(arg->precision);
	ft_putstr("\n");
	ft_putstr("res = ");
	ft_putstr(arg->res);
	ft_putstr("\n");
	ft_putstr("size = ");
	ft_putstr(arg->size);
	ft_putstr("\n--------\n");
}
*/
