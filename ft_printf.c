/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/10/23 17:09:45 by smakni           ###   ########.fr       */
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
	arg->check = 0;
	arg->count = 0;
}

void	free_arg(t_format *arg)
{
	ft_strdel(&arg->str);
	arg->len = 0;
	ft_strdel(&arg->option);
	arg->width = 0;
	arg->precision = 0;
	if (!ft_strcmp(arg->size, HH) && !ft_strcmp(arg->size, LL))
		ft_strdel(&arg->size);
	arg->type = 0;
	ft_strdel(&arg->res);
	arg->check = 0;
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
	int			save;
	char		*result;
	t_format 	*arg;

	if (!(arg = ft_memalloc(sizeof(t_format))))
		return (0);
	init_struc(arg);	
	va_start(av, format);
	result = ft_memalloc(1);
	save = 0;
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
			if (arg->check == -1)
			{
				write(1, result, save);
				return (-1);
			}
			result = ft_memjoin(result, arg->res, ret, arg->count);
			//ft_aff_param(arg);
			ret += arg->count;
			save = ret;
			free_arg(arg);
			i++;
		}
		else
		{	
			len = len_x(format, i, '%');
			result = ft_memjoin(result, ft_strsub(format, i, len), ret, len);
			ret += len;
		}
		i += len;
	}
	write(1, result, ret);
	ft_strdel(&result);
	free(arg);
	va_end(av);
	return (ret);
}

