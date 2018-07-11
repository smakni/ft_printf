/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/07/12 00:19:13 by sabri            ###   ########.fr       */
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
}

int		ft_printf(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	int			j;
	int			ret;
	t_format 	*arg;

	arg = ft_memalloc(sizeof(t_format));
	init_struc(arg);	
	tmp = ft_strdup(format);
	va_start(av, format);
	i = 0;
	j = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			arg->type = check_conv(tmp);
			if (arg->type == '%')
				i++;
			arg->str = ft_strsub(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, format[i], arg->type));
			ft_analyse(arg);
			ft_conversion(arg, av);
			//ft_aff_param(arg);
			tmp = ft_strsub_free(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, format[i], '\0'));
			i += arg->len;
			ret += arg->count;
			free_arg(arg);
		}
		else
		{
			ft_putchar(format[i]);
			j++;
		}
		i++;
	}
	free(arg);
	ft_strdel(&tmp);
	va_end(av);
	return (ret + j);
}

//-----------------------------------------------------------------------------------//

int		ft_printf_param(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	int			j;
	int			ret;
	t_format 	*arg;

	arg = ft_memalloc(sizeof(t_format));
	init_struc(arg);	
	tmp = ft_strdup(format);
	va_start(av, format);
	i = 0;
	j = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			arg->type = check_conv(tmp);
			if (arg->type == '%')
				i++;
			arg->str = ft_strsub(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, format[i], arg->type));
			ft_analyse(arg);
			ft_conversion(arg, av);
			ft_aff_param(arg);
			tmp = ft_strsub_free(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, format[i], '\0'));
			i += arg->len;
			ret += arg->count;
			free_arg(arg);
		}
		else
		{
			ft_putchar(format[i]);
			j++;
		}
		i++;
	}
	free(arg);
	ft_strdel(&tmp);
	va_end(av);
	return (ret + j);
}