/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/08/09 12:35:31 by smakni           ###   ########.fr       */
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
	check = conversion_null(arg, nb);
	if (arg->precision >= (len_nb = ft_strlen(nb)))
		nb = conversion_d2(arg, nb);
	if (arg->width > (len_nb = ft_strlen(nb)))
		conversion_d3(arg, nb, i, len_nb);
	else if (check == 0 || ((arg->type == 'o' || arg->type == 'O')
							&& ft_strchr(arg->option, '#') != 0))
		arg->res = ft_strdup(nb);
	if (ft_strchr(arg->option, ' ') != 0 
		&& arg->width <= len_nb && ft_isdigit(nb[0]) != 0)
	{
		tmp = ft_memalloc(2 + ft_strlen(arg->res));
		tmp[0] = ' ';
		tmp[1] = '\0';
		tmp = ft_strcat(tmp, arg->res);
		ft_strdel(&arg->res);
		arg->res = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (ft_strchr(arg->option, ' ') != 0 
				&& ft_strchr(arg->option, '+') == 0 && arg->width > len_nb)
		arg->res[0] = ' ';
	arg->count = ft_strlen(arg->res);
	conversion_x1(arg, nb);
	ft_strdel(&nb);
	ft_putstr(arg->res);
}

char	*conversion_d1(t_format *arg, char *nb)
{
	int i;
	char *tmp;

	i = 0;
	if (ft_strchr(arg->option, '+') != 0 && nb[0] != '-') 
	{
		tmp = ft_memalloc(2 + ft_strlen(nb));
		tmp[0] = '+';
		nb = ft_strcat(tmp, nb);
	}
	else if ((arg->type == 'o' || arg->type == 'O') 
				&& ft_strchr(arg->option, '#') != 0
				&& nb[0] != '0')
	{
		tmp = ft_memalloc(2 + ft_strlen(nb));
		tmp[0] = '0';
		nb = ft_strcat(tmp, nb);
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
	conversion_d4(arg);
	if (ft_strchr(arg->option, '-') != 0)
		while (nb[i])
		{
			arg->res[i] = nb[i];
			i++;
		}
	else if (ft_isdigit(nb[0]) == 0 && ft_strchr(arg->option, '0') != 0 
			&& ft_strchr(arg->option, '-') == 0 && arg->precision == 0) 
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

void	conversion_d4(t_format *arg)
{
	arg->res = ft_memalloc(arg->width + 1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0 
		&& arg->precision == 0 && ft_strchr(arg->str, '.') == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
}

int		conversion_null(t_format *arg, char *nb)
{
	int check;

	check = 0;
	if (nb[0] == '0' && ft_strchr(arg->str, '.') != 0 
			&& arg->precision == 0 && arg->width == 0)
	{
		arg->res = ft_memalloc(1);
		check = 1;
	}
	else if (ft_isdigit(nb[0]) == 0 && nb[1] == '0' 
				&& ft_strchr(arg->str, '.') != 0 && arg->precision == 0 
				&& arg->width == 0)
	{
		arg->res = ft_memalloc(2);
		arg->res[0] = nb [0];
		check = 2;
	}
	return (check);
}

void	conversion_x1(t_format *arg, char *nb)
{
	if (arg->type == 'x' && ft_strchr(arg->option, '#') != 0)
	{
		ft_putstr("0x");
		arg->count += 2;
	}
	else if (arg->type == 'X' && ft_strchr(arg->option, '#') != 0)
	{
		ft_putstr("0X");
		arg->count += 2;
	}
	else if ((arg->type == 'o' || arg->type == 'O') 
				&& ft_strchr(arg->option, '#') != 0
				&& nb[0] != '0')
		arg->res[0] = '0';
}