/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:15:56 by smakni            #+#    #+#             */
/*   Updated: 2018/06/19 18:43:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format **arg, va_list av)
{
	/*if (check_str((*arg)->str) != 0)
	{
		return ;
	}*/
	(*arg)->res = ft_itoa(va_arg(av, int));
	ft_putstr((*arg)->res);
}

void	conversion_s(t_format **arg, va_list av)
{
	(*arg)->res = va_arg(av, char *);
	ft_putstr((*arg)->res);
}

void	conversion_c(t_format **arg, va_list av)
{
	unsigned char	c;
	int				i;

	while ((*arg)->str[i] != (*arg)->type)
	{	
		if((*arg)->str[i] <= '0' || (*arg)->str[i] > '9')
			return ;
		i++;
	}
	c = (va_arg(av, int));
	if ((*arg)->width > 1)
	{
		if (!((*arg)->res = ft_memalloc((*arg)->width - 1)))
			return ;
		ft_memset((*arg)->res, ' ', (*arg)->width - 1);
		ft_putstr((*arg)->res);
	}
	ft_putchar(c);
}

