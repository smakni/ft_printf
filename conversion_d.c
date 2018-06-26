/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/06/27 00:24:17 by sabri            ###   ########.fr       */
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
	nb = NULL;
	nb = conversion_d1(arg, av);
	len_nb = ft_strlen(nb);
	if (arg->precision >= len_nb)
		nb = conversion_d2(arg, nb);
	if (arg->width <= len_nb)
		arg->res = ft_strdup(nb);
	else if (arg->width > arg->precision)
		conversion_d3(arg, nb, len_nb, i);
	else if (arg->width < arg->precision)
		conversion_d4(arg, nb, len_nb, i);
	//arg->res = nb;
	ft_strdel(&nb);
	ft_putstr(arg->res);
	//ft_strdel(&arg->res);
}

//revoir le if initial 
//gere conversion de precisison avec '-' et '+'
//pour stocker le nb final a envoyer dans la suite de la fonction

char	*conversion_d1(t_format *arg, va_list av)
{
	int i;
	char *tmp;
	char *nb;

	i = 0;
	nb = ft_itoa(va_arg(av, int));
	if (ft_strchr(arg->option, '+') != 0 && nb[0] != '-') 
	{
		tmp = ft_memalloc(ft_strlen(nb) + 2);
		tmp[0] = '+';
		while (nb[i])
		{
			tmp[i + 1] = nb[i];
			i++;
		}
		ft_strdel(&nb);
		nb = tmp;
	}
	return (nb);
}

char 	*conversion_d2(t_format *arg, char *nb)
{
	int i;
	char *tmp;

	i = 0;
	if (nb[0] == '-' || nb[0] == '+')
	{
		tmp = ft_memalloc(arg->precision + 1);
		ft_memset(tmp, '0', arg->precision);
		tmp[0] = nb[0];
		i++;
		while (nb[i])
		{
			tmp[arg->precision + 1 - ft_strlen(nb) + i] = nb[i];
			i++;
		}
		ft_strdel(&nb);
		nb = tmp;
	}
	else
	{
		tmp = ft_memalloc(arg->precision + 1);
		ft_memset(tmp, '0', arg->precision);
		while (nb[i])
		{
			tmp[arg->precision - ft_strlen(nb) + i] = nb[i];
			i++;
		}
		ft_strdel(&nb);
		nb = tmp;
	}
	return (nb);
	
	
}

void	conversion_d3(t_format *arg, char *nb, int len_nb, int i)
{
		arg->res = ft_memalloc(arg->width + 2);	
		if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
			ft_memset(arg->res, '0', arg->width);
		else
			ft_memset(arg->res, ' ', arg->width);
		if (ft_strchr(arg->option, '-') != 0)
			while (nb[i])
			{
				arg->res[i] = nb[i];
				i++;
			}
		else
			while (nb[i])
			{
				arg->res[arg->width - len_nb + i] = nb[i];
				i++;
			}
}

void	conversion_d4(t_format *arg, char *nb, int len_nb, int i)
{
		arg->res = ft_memalloc(arg->precision + 1);
		ft_memset(arg->res, '0', arg->precision - len_nb);
		while (i < len_nb)
		{
			arg->res[arg->precision - len_nb + i] = nb[i];
			i++;
		}
}