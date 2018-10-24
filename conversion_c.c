/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:13:03 by sabri             #+#    #+#             */
/*   Updated: 2018/10/24 16:13:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_c(t_format *arg, wchar_t c)
{
	if (c <= 127)
		return (1);
	else if ((arg->type == 'c' && ft_strcmp(arg->size, "l") == 0)
				|| arg->type == 'C')
	{
		if (c < 256 && MB_CUR_MAX == 1)
			return (1);
		else if (c <= 2047 && MB_CUR_MAX >= 2)
			return (2);
		else if (c <= 65536 && MB_CUR_MAX >= 3)
			return (3);
		else if (c < 1114111 && MB_CUR_MAX >= 4)
			return (4);
		return (3);
	}
	return (1);
}

static int	check_error(int c)
{
	if ((c >= 55296 && c <= 57343) || c > 1114111)
		return (-1);
	if (c <= 127)
		return (1);
	else if (c < 256 && MB_CUR_MAX == 1)
		return (1);
	else if (c <= 2047 && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 65536 && MB_CUR_MAX >= 3)
		return (3);
	else if (c < 1114111 && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

static int	check_error_C(unsigned int c)
{
	if ((c >= 55296 && c <= 57343) || c > 1114111)
		return (-1);
	if (c <= 127)
		return (1);
	else if (c < 256 && MB_CUR_MAX == 1)
		return (1);
	else if (c <= 2047 && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 65536 && MB_CUR_MAX >= 3)
		return (3);
	else if (c < 1114111 && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

static void	conversion_c1(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check)) == NULL)
		return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res = ft_memjoin(arg->res, tmp, check, (arg->width - check));
}

static void	conversion_c2(t_format *arg, int check)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width - check + 1)) == NULL)
		return ;
	ft_memset(tmp, ' ', arg->width - check);
	arg->res = ft_memjoin(tmp, arg->res, (arg->width - check), check);
}

void		conversion_c(t_format *arg, va_list av)
{
	wchar_t	c;
	int		check;

	c = va_arg(av, wchar_t);
	if (((arg->type == 'c' && ft_strcmp(arg->size, "l") == 0)
			|| arg->type == 'C') && (arg->check = check_error_C(c)) == -1)
		return ;
	else if ((arg->check = check_error(c)) == -1)
		return ;
	check = check_c(arg, c);
	arg->res = ft_memalloc(check);
	arg->res = ft_strdup(ft_putchar_printf(c, arg->res, check));
	if (arg->width > check)
	{
		if (ft_strchr(arg->option, '-') != 0)
			conversion_c1(arg, check);
		else
			conversion_c2(arg, check);
		arg->count = arg->width;
	}
	else
		arg->count = check;
}
