/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:59:36 by smakni            #+#    #+#             */
/*   Updated: 2018/10/31 15:34:04 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_error_c(unsigned int c)
{
	if ((c >= 55296 && c <= 57343) || c > 1114111)
		return (-1);
	else if (c <= 127)
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

static int		check_x(unsigned int c)
{
	if (c <= 127)
		return (1);
	else if (c < 256)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65536)
		return (3);
	else if (c < 1114111)
		return (4);
	else
		return (0);
}

static int		ft_strwlen2(const wchar_t *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

static	char	*get_c(char *ret, wchar_t c, int x)
{
	char *tmp_c;

	tmp_c = ft_memalloc(x + 1);
	tmp_c = ft_putchar_printf(c, tmp_c, x);
	ret = ft_strjoin_2free(ret, tmp_c);
	return (ret);
}

char			*conversion_bs(t_format *arg, va_list av)
{
	wchar_t	*tmp;
	int		x;
	int		len;
	int		i;
	char	*ret;

	i = 0;
	x = 0;
	if ((tmp = va_arg(av, wchar_t *)) == NULL)
		return (NULL);
	len = ft_strwlen2(tmp);
	ret = ft_memalloc(1);
	while (i <= len)
	{
		x = check_x(tmp[i]);
		if (arg->precision > 0 && (i + x) > arg->precision)
			break ;
		if ((x = check_error_c(tmp[i])) == -1)
		{
			arg->check = -1;
			break ;
		}
		ret = get_c(ret, tmp[i++], x);
	}
	arg->count = ft_strlen(ret);
	return (ret);
}
