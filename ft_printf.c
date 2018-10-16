/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/10/16 14:45:53 by smakni           ###   ########.fr       */
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
	if (arg->size != HH && arg->size != LL)
		ft_strdel(&arg->size);
	arg->type = 0;
	ft_strdel(&arg->res);
	arg->check = 0;
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
	char		*result;
	t_format 	*arg;

	if (!(arg = ft_memalloc(sizeof(t_format))))
		return (0);
	init_struc(arg);	
	va_start(av, format);
	result = ft_memalloc(1);
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
			result = ft_strjoin(result, arg->res);
			if (arg->check == -1)
				return (-1);
			i += arg->len;
			//ft_aff_param(arg);
			free_arg(arg);
		}
		else
		{
			len = len_x(format, i, '%');
			result = ft_strjoin(result, ft_strsub(format, i, len));
			free_arg(arg);
			//ft_putchar(format[i]);
			ret++;
		}
		i += len;
	}
	ft_putstr(result);
	ft_strdel(&result);
	free(arg);
	va_end(av);
	return (ret);
}

/*
int		ft_printf(const char *format, ...)
{
	va_list 	av;
	int 		i;
	int			ret;
	int			len;
	t_format 	*arg;
	t_list		*head;
	t_list		*new;

	if (!(arg = ft_memalloc(sizeof(t_format))))
		return (0);
	if (!(head = ft_memalloc(sizeof(t_list))))
		return (0);
	if (!(new = ft_memalloc(sizeof(t_list))))
		return (0);
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
			if (head->content == NULL)
				head = ft_lstnew(arg->res, arg->count);
			else
			{
				//ft_putstr("ELSE");
				new = ft_lstnew(arg->res, arg->count);
				ft_lstadd(&head, new);
			}
			//ft_putstr(head->content);
			if (new->content != NULL)
			//	ft_putstr(new->content);
			if (arg->check == -1)
				return (-1);
			i += arg->len;
			ret += arg->count;
			//ft_aff_param(arg);
			free_arg(arg);
		}
		else
		{
			len = len_x(format, i, '%');
			new = ft_lstnew(ft_strsub(format, i, len), len);
			ft_lstadd(&head, new);
			//ft_putchar(format[i]);
			ret++;
		}
		i += len;
	}
	while (head)
	{
		ft_putstr(head->content);
		head = head->next;
	}
	free(arg);
	va_end(av);
	return (ret);
}
*/