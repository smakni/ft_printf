/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/26 19:31:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

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
}

int		ft_printf(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	t_format 	*arg;

	arg = ft_memalloc(sizeof(t_format));
	init_struc(arg);	
	tmp = ft_strdup(format);
	va_start(av, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			arg->type = check_conv(tmp);
			arg->str = ft_strsub(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, '%', arg->type));
			ft_analyse(arg);
			ft_conversion(arg, av);
			ft_aff_param(arg);
			tmp = ft_strsub_free(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, '%', '\0'));
			i += arg->len;
			free_arg(arg);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	free(arg);
	ft_strdel(&tmp);
	ft_putstr("\nEND\n");
	va_end(av);
	return (i);
}
