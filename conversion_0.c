/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 01:10:30 by sabri             #+#    #+#             */
/*   Updated: 2018/10/17 17:27:20 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_0(t_format *arg)
{
	if (arg->width > 1)
	{
		if (ft_strchr(arg->option, '-') != 0)
		{	
			arg->res = ft_memalloc(arg->width + 1);
			ft_memset(arg->res, ' ', arg->width);
			arg->res[0] = '%';
		}
		else if (ft_strchr(arg->option, '0') != 0)
		{		
			arg->res = ft_memalloc(arg->width + 1);
			ft_memset(arg->res, '0', arg->width);
			arg->res[arg->width - 1] = '%';
		}
		else
		{
			arg->res = ft_memalloc(arg->width + 1);
			ft_memset(arg->res, ' ', arg->width);
			arg->res[arg->width - 1] = '%';
		}
	}
	else
	{
		arg->res = ft_memalloc(2);
		arg->res[0] = '%';
	}
	arg->count += ft_strlen(arg->res);
}
