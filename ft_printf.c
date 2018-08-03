/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/08/03 12:28:49 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struc(t_format *arg)
{
	arg->str = NULL;
	arg->len = 0;
	arg->option = NULL;
	arg->width = 0;
	arg->precision = 0;
	arg->size = NULL;
	arg->type = 0;
	arg->res = NULL;
	arg->count = 0;
}

void	free_arg(t_format *arg)
{
	ft_strdel(&arg->str);
	arg->len = 0;
	ft_strdel(&arg->option);
	arg->width = 0;
	arg->precision = 0;
	if (arg->size != HH && arg->size != LL)
		ft_strdel(&arg->size);
	arg->type = 0;
	ft_strdel(&arg->res);
	arg->count = 0;
}

int		len_x(const char *str, int x, char c)
{
	int count;

	count = 1;
	while (str[x + count] && str[x + count] != c)
		count++;
	return(count);
}

int		ft_printf(const char *format, ...)
{
	va_list 	av;
	int 		i;
	int			ret;
	int			len;
	t_format 	*arg;

	arg = ft_memalloc(sizeof(t_format));
	init_struc(arg);	
	va_start(av, format);
	i = 0;
	ret = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			arg->type = check_conv(format, i);
			len = len_x(format, i, arg->type);
			arg->str = ft_strsub(format, i + 1, len);
			ft_analyse(arg);
			ft_conversion(arg, av);
			i += arg->len;
			ret += arg->count;
			//ft_aff_param(arg);
			free_arg(arg);
		}
		else
		{
			ft_putchar(format[i]);
			ret++;
		}
		i++;
	}
	free(arg);
	va_end(av);
	return (ret);
}
