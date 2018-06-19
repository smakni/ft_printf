/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:15:56 by smakni            #+#    #+#             */
/*   Updated: 2018/06/19 21:32:20 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format **arg, va_list av)
{
	int			len_nb;
	char		*nb;
	int			i;
	int			w;


	i = 0;
	nb = ft_itoa(va_arg(av, int));
	len_nb = ft_strlen(nb);
	if ((*arg)->width > 1)
	{
		w = (*arg)->width;
		(*arg)->res = ft_memalloc(w);
	}
	if ((*arg)->width > 1 && ft_strchr((*arg)->option, '0') != 0)
		ft_memset((*arg)->res, '0', w - len_nb);
	while (i < len_nb)
	{
		(*arg)->res[w - len_nb + i] = nb[i];
		i++;
	}
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

