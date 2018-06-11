/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/11 20:50:29 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv(char c, va_list av)
{
	t_format arg;
	char 	*str;
	char	*l;
	int		x;
	void	(*pf1)(char *);

	pf1 = &ft_putstr;
	if (c == 's')
	{
		str = va_arg(av, char *);
		return (str);
	}
	if (c == 'd')
	{
		x = va_arg(av, int);
		return (ft_itoa(x));
	}
	if (c == 'c')
	{
		l = va_arg(av, char *);
		return(l);
	}
	return(NULL);
}


int		ft_printf(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	t_format 	*arg;

	tmp = (char *)format;
	va_start(av, format);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '%' && tmp[i + 1] != '%')
		{
			i++;
			arg->str = ft_conv(tmp[i], av);
			ft_putstr(arg->str);
		}
		else
			ft_putchar(tmp[i]);
		i++;
	}
	va_end(av);
	return (i);
}
