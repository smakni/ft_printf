/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/20 04:52:54 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_from(char *str, char start, char end)
{
	int i;	
	int count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != start)
		i++;
	while (str[i + count] && str[i + count] != end)
		count++;
	return (count);
}

void	ft_analyse(t_format *arg)
{
	arg->len = ft_strlen(arg->str);
	arg->option = check_option(arg->str);
	arg->width = check_widht(arg->str);
	arg->precision = check_precision(arg->str);
}

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
	ft_putstr("\n--------\n");
}
void 	ft_conversion(t_format *arg, va_list av)
{
	if (arg->type == 'd')
		conversion_d(arg, av);
	if (arg->type == 'c')
		conversion_c(arg, av);
	if (arg->type == 's')
		conversion_s(arg, av);
	return ;
}

void	free_arg(t_format *arg)
{
	free(arg->str);
	free(arg->option);
	free(arg->size);
}

void	init_struc(t_format *arg)
{
	arg->str = NULL;
	arg->len = 0;
	arg->option = NULL;
	arg->width = 0;
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
			//ft_aff_param(arg);
			tmp = ft_strsub_free(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, '%', '\0'));
			i += arg->len;
			free_arg(arg);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	free(arg);
	free(tmp);
	ft_putstr("\nEND\n");
	va_end(av);
	return (i);
}
