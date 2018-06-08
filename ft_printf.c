/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/08 16:43:29 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv(char c, va_list av)
{
	char 	*str;
	char	l;
	int		x;

	if (c == 's')
	{
		str = va_arg(av, char *);
		ft_putstr(str);
	}
	if (c == 'd')
	{
		x = va_arg(av, int);
		ft_putnbr(x);
	}
	if (c == 'c')
	{
		l = va_arg(av, int);
		ft_putchar(l);
	}
}


int		ft_printf(const char *format, ...)
{
	va_list av;
	char 	*tmp;
	int 	i;

	tmp = (char *)format;
	va_start(av, format);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '%' && tmp[i + 1] != '%')
		{
			i++;
			ft_conv(tmp[i], av);
		}
		else
			ft_putchar(tmp[i]);
		i++;
	}
	va_end(av);
	return (i);
}
