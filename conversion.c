/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:15:56 by smakni            #+#    #+#             */
/*   Updated: 2018/06/24 01:35:11 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format *arg, va_list av)
{
	int		len_nb;
	char	*nb;
	int		i;

	i = 0;
	nb = ft_itoa(va_arg(av, int));
	len_nb = ft_strlen(nb);
	if (arg->width < len_nb && arg->precision < len_nb)
		arg->res = ft_strdup(nb);
	else if (arg->width >= arg->precision)
	{
		arg->res = ft_memalloc(arg->width + 1);
		ft_memset(arg->res, ' ', arg->width);
		if (arg->precision > len_nb)
			ft_memset_from(arg->res, arg->width - arg->precision, '0', arg->precision);
		while (i < len_nb)
		{
			arg->res[arg->width - len_nb + i] = nb[i];
			i++;
		}
	}
	else if (arg->width < arg->precision && ft_strlen(arg->option) == 0)
	{	
		arg->res = ft_memalloc(arg->precision + 1);
		ft_memset(arg->res, '0', arg->precision - len_nb);
		while (i < len_nb)
		{
			arg->res[arg->precision - len_nb + i] = nb[i];
			i++;
		}
	}
	ft_strdel(&nb);
	ft_putstr(arg->res);
}








/*
void	conversion_d(t_format *arg, va_list av) //check precisison avant check largeur
{
	int			len_nb;
	char		*nb;
	int			i;

	i = -1;
	nb = ft_itoa(va_arg(av, int));
	len_nb = ft_strlen(nb);
	if (strchr(arg->str, '.'))
	{
		if (arg->width > arg->precision)
		{
			arg->res = ft_memalloc(arg->width + 1);
			while (i++ < len_nb)
				arg->res[arg->width - len_nb + i] = nb[i];
			i = 0;
			while (arg->res[i] != nb[0])
		}
		else
			arg->res = ft_memalloc(arg->precision + 1);
		ft_memset(arg->res, '0', arg->precision - len_nb);
		while (i++ < len_nb)
			arg->res[arg->precision - len_nb + i] = nb[i];
	}
	else if (ft_strchr(arg->str, '-') == 0 && arg->width > len_nb)
	{
		arg->res = ft_memalloc(arg->width + 1);
		if (ft_strchr(arg->option, '0') != 0)
			ft_memset(arg->res, '0', arg->width - len_nb);
		else if (ft_strlen(arg->option) == 0)
			ft_memset((arg)->res, ' ', (arg)->width - len_nb);
		while (i++ < len_nb)
			arg->res[arg->width - len_nb + i] = nb[i];
		if (ft_strchr(arg->option, ' ') != 0 && ft_strchr(arg->option, '0') != 0)
			arg->res[0] = ' ';
	}
	else
		conversion_d2(arg, len_nb, nb);
	ft_putstr(arg->res);
	ft_strdel(&nb);
	//ft_strdel(&(arg)->res);
}

void	conversion_d2(t_format *arg,int len_nb, char *nb)
{
	int i;

	i = 0;
	if (arg->width > len_nb)
	{
		arg->res = ft_memalloc(arg->width + 1);
		while (arg->res[i] || i < len_nb)
		{
			arg->res[i] = nb[i];
			i++;
		}
		while (i < arg->width)
		{
			arg->res[i] = ' ';
			i++;
		}
		arg->res[i] = '\0';
	}
	else
		arg->res = nb;
}
*/

void	conversion_s(t_format *arg, va_list av)
{
	char 	*tmp;
	int		i;

	if (arg->precision == -1)
	{
		return ft_putstr(va_arg(av, char *));
	}
	tmp = ft_strdup(va_arg(av, char *));
	i = 0;
	while(tmp[i] && i < arg->precision)
		i++;
	arg->res = ft_strsub_free(tmp, 0, i);
	ft_putstr(arg->res);
}

void	conversion_c(t_format *arg, va_list av)
{
	int				i;

	i = 0;
	while (arg->str[i] != arg->type)
	{	
		if(arg->str[i] <= '0' || arg->str[i] > '9')
			return ;
		i++;
	}
	if (arg->width > 1) 
	{
		if (!(arg->res = ft_memalloc(arg->width)))
			return ;
		ft_memset(arg->res, ' ', arg->width - 1);
		ft_putstr(arg->res);
		ft_strdel(&(arg)->res);
	}
	ft_putchar(va_arg(av, int));
}
