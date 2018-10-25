/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 01:10:30 by sabri             #+#    #+#             */
/*   Updated: 2018/10/25 14:44:39 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_1(t_format *arg)
{
	arg->res = ft_memalloc(arg->width + 1);
	ft_memset(arg->res, ' ', arg->width);
	arg->res[0] = '%';
}

void		conversion_0(t_format *arg)
{
	if (arg->width > 1)
	{
		if (ft_strchr(arg->option, '-') != 0)
			case_1(arg);
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
	arg->count = ft_strlen(arg->res);
}
