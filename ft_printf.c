/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/10/31 12:00:12 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struc(t_format *arg, t_control *ctr)
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
	ctr->i = 0;
	ctr->ret = 0;
	ctr->len = 0;
}

void	free_arg(t_format *arg)
{
	ft_strdel(&arg->str);
	arg->len = 0;
	ft_strdel(&arg->option);
	arg->width = 0;
	arg->precision = 0;
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
	return (count);
}

void	case_3(t_format *arg, t_control *ctr, const char *format)
{
	char *tmp;

	tmp = NULL;
	ctr->len = len_x(format, ctr->i, arg->type);
	tmp = ft_strsub(format, ctr->i + 1, 0);
	ctr->result = ft_memjoin(ctr->result, tmp, ctr->ret, 0);
	ctr->i += ctr->len;
	ft_strdel(&tmp);
}

int		case_1(t_format *arg, t_control *ctr, const char *format, va_list av)
{
	arg->type = check_conv(format, ctr->i);
	if (ft_strchr(CONV, arg->type) == 0)
	{	
		case_3(arg, ctr, format);
		return (0);
	}
	ctr->len = len_x(format, ctr->i, arg->type);
	arg->str = ft_strsub(format, ctr->i + 1, ctr->len);
	ft_analyse(arg);
	ft_conversion(arg, av);
	if (arg->check == -1)
	{
		free_arg(arg);
		write(1, ctr->result, arg->save);
		return (-1);
	}
	ctr->result = ft_memjoin(ctr->result, arg->res, ctr->ret, arg->count);
	ctr->ret += arg->count;
	arg->save = ctr->ret;
	ctr->i += (ft_strlen(arg->str) + 1);
	free_arg(arg);
	return (0);
}

void	case_2(t_control *ctr, const char *format)
{
	char *tmp;

	tmp = NULL;
	ctr->len = len_x(format, ctr->i, '%');
	tmp = ft_strsub(format, ctr->i, ctr->len);
	ctr->result = ft_memjoin(ctr->result, tmp, ctr->ret, ctr->len);
	ctr->ret += ctr->len;
	ctr->i += ctr->len;
	ft_strdel(&tmp);
}

int		ft_printf(const char *format, ...)
{
	va_list		av;
	t_format	*arg;
	t_control	*ctr;
	int			ret;

	if (!(arg = ft_memalloc(sizeof(t_format))))
		return (0);
	if (!(ctr = ft_memalloc(sizeof(t_control))))
		return (0);
	init_struc(arg, ctr);
	va_start(av, format);
	while (format[ctr->i])
	{
		if (format[ctr->i] == '%')
		{
			if (case_1(arg, ctr, format, av) == -1)
			{
				free(ctr);
				free(arg);
				return (-1);
			}
		}
		else
			case_2(ctr, format);
	}
	write(1, ctr->result, ctr->ret);
	ft_strdel(&ctr->result);
	ret = ctr->ret;
	free(ctr);
	free(arg);
	va_end(av);
	return (ret);
}
