/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:56:36 by sabri             #+#    #+#             */
/*   Updated: 2018/07/11 00:57:52 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_o(t_format *arg, va_list av)
{
	unsigned int nb;
	int tmp;
	int i;

	i = 0;
	nb = va_arg(av, int);
	tmp = nb;
	while (nb != 0)
	{
		i++;
		nb = nb / 8;
	}
	arg->res = ft_memalloc(i + 1);
	nb = tmp;
	while (nb != 0)
	{
		i--;
		tmp = nb % 8;
		if (tmp < 8)
			tmp = tmp + 48;
		else
			tmp = tmp + 57;
		arg->res[i] = tmp;
		nb = nb / 8;
	}
	arg->count = ft_strlen(arg->res);
	ft_putstr(arg->res);
}