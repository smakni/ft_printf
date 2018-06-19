/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/19 18:07:20 by smakni           ###   ########.fr       */
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

void	ft_analyse(t_format **arg)
{
	(*arg)->len = ft_strlen((*arg)->str);
	(*arg)->option = check_option((*arg)->str);
	(*arg)->width = check_widht((*arg)->str);
	(*arg)->precision = check_precision((*arg)->str);
}

void	ft_aff_param(t_format **arg)
{
	ft_putstr("\n--------\n");
	ft_putstr("ft_analyse = ");
	ft_putstr((*arg)->str);
	ft_putstr("\n");
	ft_putstr("type = ");
	ft_putchar((*arg)->type);
	ft_putstr("\n");
	ft_putstr("len = ");
	ft_putnbr((*arg)->len);
	ft_putstr("\n");
	ft_putstr("option = ");
	ft_putstr((*arg)->option);
	ft_putstr("\n");
	ft_putstr("width = ");
	ft_putnbr((*arg)->width);
	ft_putstr("\n");
	ft_putstr("precision = ");
	ft_putnbr((*arg)->precision);
	ft_putstr("\n");
	ft_putstr("res = ");
	ft_putstr((*arg)->res);
	ft_putstr("\n--------\n");
}
void 	ft_conversion(t_format **arg, va_list av)
{
	if ((*arg)->type == 'd')
		conversion_d(arg, av);
	if ((*arg)->type == 'c')
		conversion_c(arg, av);
	if ((*arg)->type == 's')
		conversion_s(arg, av);
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	int			j;
	t_format 	*arg;

	tmp = (char *)format;
	va_start(av, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			//arg = malloc(sizeof(t_format));
			arg->type = check_conv(tmp);
			arg->str = ft_strsub(tmp, ft_strlen_c(tmp, '%') + 1, ft_strlen_from(tmp, '%', arg->type));
			ft_analyse(&arg);
			ft_conversion(&arg, av);
			ft_aff_param(&arg);
			tmp = ft_strsub(tmp, ft_strlen_c(tmp, format[i]) + 1, ft_strlen_from(tmp, '%', '\0'));
			i += arg->len;
			//free(arg->res);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	ft_putstr("\nEND\n");
	va_end(av);
	return (i);
}
