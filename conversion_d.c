/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/07/23 15:01:22 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format *arg, va_list av)
{
	int		len_nb;
	char	*nb;
	char	*tmp;
	int		i;
	int		check;

	i = 0;
	check = 0;
	tmp = NULL;
	nb = NULL;
	nb = conversion_d0(arg, nb, av);
	nb = conversion_d1(arg, nb);
	if (nb[0] == '0' && ft_strchr(arg->str, '.') != 0 && arg->precision == 0 && arg->width == 0)
	{
		arg->res = ft_memalloc(1);
		check = 1;
	}
	else if (nb[0] == '0' && ft_strchr(arg->str, '.') != 0 && ft_strchr(arg->option, ' ') != 0 && arg->precision == 0 && arg->width == 0)
	{
		arg->res = ft_memalloc(1);
		check = 1;
	}
	else if (ft_isdigit(nb[0]) == 0 && nb[1] == '0' && ft_strchr(arg->str, '.') != 0 && arg->precision == 0 && arg->width == 0)
	{
		arg->res = ft_memalloc(2);
		arg->res[0] = nb [0];
		check = 1;
	}
	len_nb = ft_strlen(nb);
	if (arg->precision >= len_nb)
		nb = conversion_d2(arg, nb);
	if (arg->width > arg->precision)
		conversion_d3(arg, nb, i, len_nb);
	else if (check == 0)
		arg->res = ft_strdup(nb);
	if (ft_strchr(arg->option, ' ') != 0 && arg->width <= len_nb && ft_isdigit(nb[0]) != 0)
	{
		tmp = ft_memalloc(2);
		tmp[0] = ' ';
		tmp[1] = '\0';
		arg->res = ft_strcat(tmp, arg->res);
	}
	else if (ft_strchr(arg->option, ' ') != 0 && ft_strchr(arg->option, '+') == 0 && arg->width > len_nb)
		arg->res[0] = ' ';
	ft_strdel(&nb);
	arg->count = ft_strlen(arg->res);
	ft_putstr(arg->res);
}

char	*conversion_d0(t_format *arg, char *nb, va_list av)
{
	if (arg->type == 'd' || arg->type == 'D')
	{
		if (arg->size[0] == '\0' && arg->type != 'D')
			nb = ft_itoa(va_arg(av, int));
		else if (arg->type == 'D'|| (arg->size[0] == 'l' && arg->size[1] == '\0'))
			nb = ft_itoa_li(va_arg(av, long int));
		else if (arg->size[0] == 'l' && arg->size[1] == 'l')
			nb = ft_itoa_lli(va_arg(av, long long int));
		else if (arg->size[0] == 'h' && arg->size[1] == '\0')
			nb = ft_itoa_hd(va_arg(av, int));
		else if (arg->size[0] == 'h' && arg->size[1] == 'h')
			nb = ft_itoa(va_arg(av, int));
		else if (arg->size[0] == 'j' && arg->size[1] == '\0')
			nb = ft_itoa_imax(va_arg(av, intmax_t));
		else if (arg->size[0] == 'z' && arg->size[1] == '\0')
			nb = ft_itoa_it(va_arg(av, size_t));
	}
	else if (arg->type == 'u')

	return (nb);
}

char	*conversion_d1(t_format *arg, char *nb)
{
	int i;
	char *tmp;

	i = 0;
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
		tmp = ft_memalloc(arg->precision + 2);
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

void	conversion_d3(t_format *arg, char *nb, int i, int len_nb)
{
	arg->res = ft_memalloc(arg->width + 1);	
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0 && arg->precision == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
	if (ft_strchr(arg->option, '-') != 0)
		while (nb[i])
		{
			arg->res[i] = nb[i];
			i++;
		}
	else if (arg->precision > len_nb && ft_isdigit(nb[0]) == 0)
		while (nb[i])
		{
			arg->res[arg->width - arg->precision + i - 1] = nb[i];
			i++;
		}
	else if (arg->precision > len_nb)
		while (nb[i])
		{
			arg->res[arg->width - arg->precision + i] = nb[i];
			i++;
		}
	else if (ft_strchr(arg->option, '0') != 0 && ft_isdigit(nb[0]) == 0)
	{
		arg->res[0] = nb[0];
		i++;
		while (nb[i])
		{
			arg->res[arg->width - len_nb + i] = nb[i];
			i++;
		}
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
		ft_memset(arg->res, '0', arg->precision);
		while (i < len_nb)
		{
			arg->res[arg->precision - len_nb + i] = nb[i];
			i++;
		}
}