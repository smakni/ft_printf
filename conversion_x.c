/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:07:08 by sabri             #+#    #+#             */
/*   Updated: 2018/07/10 13:38:59 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_x(t_format *arg, va_list av)
{
	int nb;
	int tmp;
	int i;

	i = 0;
	nb = va_arg(av, int);
	tmp = nb;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	arg->res = ft_memalloc(i + 1);
	nb = tmp;
	while (nb != 0)
	{
		i--;
		tmp = nb % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 87;
		arg->res[i] = tmp;
		nb = nb / 16;
	}
	arg->count = ft_strlen(arg->res);
	ft_putstr(arg->res);
}