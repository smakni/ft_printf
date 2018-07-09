/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:22:09 by sabri             #+#    #+#             */
/*   Updated: 2018/07/10 00:41:00 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_p(t_format *arg, va_list av)
{
	void		*adr;
	int			tmp;
	long int	nb;
	int			i;

	i = 0;
	(void)arg;
	adr = va_arg(av, void*);
	nb = (long int)adr;
	while (nb != 0)
	{
		i++;
		nb = nb / 16;
	}
	arg->res = ft_memalloc(i + 1);
	nb = (long int)adr;
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
	ft_putstr("0x");
	ft_putstr(arg->res);
}