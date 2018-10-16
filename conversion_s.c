/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:41:00 by sabri             #+#    #+#             */
/*   Updated: 2018/09/14 13:53:07 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_s(t_format *arg, va_list av)
{
	char 	*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = va_arg(av, char *);
	if (arg->precision == 0 && ft_strchr(arg->str, '.') != 0
			&& arg->width == 0)
		return ;
	if (tmp == NULL || (arg->precision == 0
			&& ft_strchr(arg->str, '.') != 0))
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp);
	len = ft_strlen(tmp);
	if (arg->precision < len && arg->precision != 0)
	{
		tmp = conversion_s1(arg, tmp);
		len = ft_strlen(tmp);
	}
	if ((ft_strcmp(tmp,"(null)")) == 0 && arg->width > 0
			&& ft_strchr(arg->str, '.') != 0)
		tmp = ft_strdup("");
	if (arg->width > len 
			|| ((ft_strcmp(tmp,"")) == 0 && arg->width > 0))
		arg->res = conversion_s2(arg, tmp, len, i);
	else
		arg->res = ft_strdup(tmp);
	ft_strdel(&tmp);
	arg->count = ft_strlen(arg->res);
}

char	*conversion_s1(t_format *arg, char *tmp)
{
	int i;

	i = 0;
	while(tmp[i] && i < arg->precision)
		i++;
	tmp = ft_strsub_free(tmp, 0, i);
	return (tmp);
}

char	*conversion_s2(t_format *arg, char *tmp, int len, int i)
{
	arg->res = ft_memalloc(arg->width + 1);
	if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
		ft_memset(arg->res, '0', arg->width);
	else
		ft_memset(arg->res, ' ', arg->width);
	if (ft_strchr(arg->option, '-') != 0)
		while (tmp[i])
		{
			arg->res[i] = tmp[i];
			i++;
		}
	else
		while (tmp[i])
		{
			arg->res[arg->width - len + i] = tmp[i];
			i++;
		}
	return (arg->res);
}
