/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:12:30 by sabri             #+#    #+#             */
/*   Updated: 2018/10/30 14:28:56 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_d(t_format *arg, va_list av)
{
	int		len_nb;
	char	*nb;
	char	*tmp;
	int		check;

	check = 0;
	tmp = NULL;
	nb = NULL;
	nb = conversion_d0(arg, nb, av);
	nb = conversion_d1(arg, nb);
	check = conversion_null(arg, nb);
	if (check == 0 && ft_strcmp(nb, "0") == 0 && arg->precision == 0
			&& ft_strchr(arg->str, '.') != 0)
		nb = ft_strdup("");
	if (arg->precision >= (len_nb = ft_strlen(nb)))
		nb = conversion_d2(arg, nb);
	if (ft_strcmp(nb, "") != 0 && ft_strchr(arg->option, '#') != 0)
		nb = conversion_x1(arg, nb);
	if (arg->width > (len_nb = ft_strlen(nb)))
		conversion_d3(arg, nb, len_nb);
	else if (check == 0 || ((arg->type == 'o' || arg->type == 'O')
			&& ft_strchr(arg->option, '#') != 0))
		arg->res = ft_strdup(nb);
	if (arg->type != 'u' && arg->type != 'U' && ft_strchr(arg->option, ' ') != 0
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
	ft_strdel(&nb);
}

char	*conversion_d1(t_format *arg, char *nb)
{
	char *tmp;

	if (arg->type != 'u' && arg->type != 'U' && 
			ft_strchr(arg->option, '+') != 0 && nb[0] != '-')
	{
		tmp = "+";
		nb = ft_strjoin_free(tmp, nb);
	}
	else if ((arg->type == 'o' || arg->type == 'O')
				&& ft_strchr(arg->option, '#') != 0
				&& nb[0] != '0')
	{
		tmp = "0";
		nb = ft_strjoin_free(tmp, nb);
	}
	return (nb);
}

char	*conversion_d2(t_format *arg, char *nb)
{
	int		i;
	char	*tmp;

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

char	*conversion_d2x(t_format *arg, char *nb)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_memalloc(arg->precision + 3);
	ft_memset(tmp, '0', arg->precision);
	tmp[0] = '0';
	if (arg->type == 'x')
		tmp[1] = 'x';
	else
		tmp[1] = 'X';
	while (nb[i])
	{
		tmp[arg->precision - ft_strlen(nb) + i + 2] = nb[i];
		i++;
	}
	ft_strdel(&nb);
	nb = tmp;
	return (nb);
}

void	conversion_d3(t_format *arg, char *nb, int len_nb)
{
	int i;

	i = 0;
	conversion_d4(arg);
	if (ft_strchr(arg->option, '-') != 0)
		while (nb[i])
		{
			arg->res[i] = nb[i];
			i++;
		}
	else
	{
		if ((nb[0] == '-' || nb[0] == '+')
				&& ft_strchr(arg->option, '0') != 0
				&& arg->precision == 0)
			arg->res[i++] = nb[0];
		else if ((arg->type == 'x' || arg->type == 'X')
				&& ft_strchr(arg->option, '#') != 0
				&& ft_strchr(arg->option, '0') != 0
				&& ft_strchr(arg->str, '.') == 0
				&& ft_strcmp(nb, "0") != 0)
		{
			arg->res[i++] = nb[0];
			arg->res[i++] = nb[1];
		}
		while (nb[i])
		{
			arg->res[arg->width - len_nb + i] = nb[i];
			i++;
		}
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
		arg->res[0] = nb[0];
		check = 2;
	}
	return (check);
}

char	*conversion_x1(t_format *arg, char *nb)
{
	char *x;
	char *bx;

	if (ft_strcmp(nb, "0") == 0)
		return (ft_strdup("0"));
	x = NULL;
	bx = NULL;
	if (arg->type == 'x')
	{
		x = ft_memalloc(3 + ft_strlen(nb));
		x[0] = '0';
		x[1] = 'x';
		x[2] = '\0';
		x = ft_strcat(x, nb);
		ft_strdel(&nb);
		nb = ft_strdup(x);
		ft_strdel(&x);
	}
	else if (arg->type == 'X')
	{
		bx = ft_memalloc(3 + ft_strlen(nb));
		bx[0] = '0';
		bx[1] = 'X';
		bx[2] = '\0';
		bx = ft_strcat(bx, nb);
		ft_strdel(&nb);
		nb = ft_strdup(bx);
		ft_strdel(&bx);
	}
	return (nb);
}
