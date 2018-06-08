/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/08 15:29:34 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list av;
	size_t 	i;

	va_start(av, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			check(str[i + 1]) == flag;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(av);
	return (len);
}
