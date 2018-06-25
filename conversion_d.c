/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/06/25 23:12:47 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format *arg, va_list av)
{
	int		len_nb;
	char	*nb;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	nb = ft_itoa(va_arg(av, int));
	if (nb > 0 && ft_strchr(arg->option, '+') != 0)
		nb = conversion_d1(nb);
	len_nb = ft_strlen(nb);
	if (arg->width < len_nb && arg->precision < len_nb)
		arg->res = ft_strdup(nb);
	else if (arg->width >= arg->precision)
		conversion_d2(arg, nb, len_nb, i);
	else if (arg->width < arg->precision)
		conversion_d3(arg, nb, len_nb, i);
	ft_strdel(&nb);
	ft_putstr(arg->res);
	ft_strdel(&arg->res);
}

char	*conversion_d1(char *nb)
{
	int i;
	int len_nb;
	char *tmp;

	i = 0;
	len_nb = ft_strlen(nb);
	tmp = ft_memalloc(len_nb + 1);
	tmp[0] = '+';
	while (nb[i])
	{
		tmp[i + 1] = nb[i];
		i++;
	}
	i = 0;
	ft_strdel(&nb);
	nb = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (nb);
}

void	conversion_d2(t_format *arg, char *nb, int len_nb, int i)
{
		arg->res = ft_memalloc(arg->width + 1);	
		if (ft_strchr(arg->option, '0') != 0)
			ft_memset(arg->res, '0', arg->width);
		else
			ft_memset(arg->res, ' ', arg->width);
		if (arg->precision > len_nb)
			ft_memset_from(arg->res, arg->width - arg->precision, '0', arg->precision);
		if (ft_strchr(arg->option, '-') != 0)
			while (nb[i])
			{
				arg->res[i] = nb[i];
				i++;
			}
		else
			while (i < len_nb)
			{
				arg->res[arg->width - len_nb + i] = nb[i];
				i++;
			}
}

void	conversion_d3(t_format *arg, char *nb, int len_nb, int i)
{
		arg->res = ft_memalloc(arg->precision + 1);
		ft_memset(arg->res, '0', arg->precision - len_nb);
		while (i < len_nb)
		{
			arg->res[arg->precision - len_nb + i] = nb[i];
			i++;
		}
}