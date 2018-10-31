/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:22:09 by sabri             #+#    #+#             */
/*   Updated: 2018/10/31 17:43:00 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_p(t_format *arg, va_list av)
{
	void				*adr;
	int					tmp;
	char				*str_tmp;
	long unsigned int	nb;
	int					i;

	i = 0;
	tmp = 0;
	str_tmp = NULL;
	adr = va_arg(av, void*);
	nb = (long unsigned int)adr;
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	str_tmp = ft_memalloc(i + 3);
	str_tmp[0] = '0';
	str_tmp[1] = 'x';
	nb = (long unsigned int)adr;
	i += 2;
	if (nb == 0)
		str_tmp[i] = '0';
	while (nb > 0)
	{
		i--;
		tmp = nb % 16;
		if (tmp < 10)
			tmp = tmp + 48;
		else
			tmp = tmp + 87;
		str_tmp[i] = tmp;
		nb = nb / 16;
	}
	if (arg->width > (int)ft_strlen(str_tmp))
	{
		arg->res = ft_memalloc(arg->width - (int)ft_strlen(str_tmp));
		if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
			ft_memset(arg->res, '0', arg->width - (int)ft_strlen(str_tmp));
		else
			ft_memset(arg->res, ' ', arg->width - (int)ft_strlen(str_tmp));
		if (ft_strchr(arg->option, '0') != 0 || ft_strchr(arg->option, '-') != 0)
			arg->res = ft_strjoin(str_tmp, arg->res);
		else
			arg->res = ft_strjoin(arg->res, str_tmp);
	}
	else
		arg->res = ft_strdup(str_tmp);
	ft_strdel(&str_tmp);
	arg->count = ft_strlen(arg->res);
}

char	*ft_strcpy_from(char *dst, const char *src, int start)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = '\0';
	return (dst);
}
