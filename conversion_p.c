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
	char				*tmp;
	char				*str_tmp;
	unsigned long		nb;

	str_tmp = NULL;
	tmp = NULL;
	adr = va_arg(av, void*);
	nb = (unsigned long)adr;
	tmp = ft_itoa_base_lui(nb, 16, 0);
	if ((int)ft_strlen(tmp) >= arg->precision)
		str_tmp = ft_memalloc(2);
	else
	{		
		str_tmp = ft_memalloc(arg->precision - (int)ft_strlen(tmp) + 2);
		ft_memset(str_tmp, '0',arg->precision - (int)ft_strlen(tmp) + 2);
	}
	str_tmp[0] = '0';
	str_tmp[1] = 'x';
	if (ft_strcmp(tmp, "0") == 0 && arg->precision == 0 
			&& ft_strchr(arg->str, '.') != 0)
		ft_strdel(&tmp);
	else
		str_tmp = ft_strjoin(str_tmp, tmp);
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
