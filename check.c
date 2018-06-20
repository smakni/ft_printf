/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:19:57 by smakni            #+#    #+#             */
/*   Updated: 2018/06/20 12:15:08 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_conv(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '%')
		i++;
	i++;
	if (str[i] == conv[j])
		return (conv[j]);
	while (str[i])
	{
		if (str[i] != conv[j])
		{
			j = 0;
			while (conv[j] && str[i] != conv[j])
				j++;
			if (str[i] == conv[j])
				return (conv[j]);
		}
		i++;
	}
	return ('Z');
}

char 	*check_option(char *str)
{
	int 	i;
	char 	*opt;

	i = 0;
	while (OPTION)
		i++;
	if (!(opt = ft_memalloc(i + 1)))
		return (NULL);
	i = 0;
	while (OPTION)
	{
		opt[i] = str[i];
		i++;
	}
	opt[i + 1] = '\0';
	return (opt);
}

int 	check_widht(char *str)
{
	int i;
	int width;
	char *tmp;

	i = 0;
	while (OPTION)
		i++;
	tmp = ft_strsub(str, i, ft_strlen_c(str, '.'));
	width = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (width);
}

int		check_precision(char *str)
{
	int i;
	int start;
	int precision;

	i = 0;
	start = 0;
	if (ft_strchr(str, '.') == 0)
		return (1);
	while(str[start] != '.')
		start++;
	start++;
	if (str[start + 1] < '0' && str[start + 1] > '9')
		return (1);
	while (str[start + i] >= '0' && str[start + i] <= '9')
		i++;
	precision = ft_atoi(ft_strsub_free(str, start, i));
	return (precision);
}

int 	check_str(char *str)
{
	int i;

	i = 0;
	while (OPTION)
		i++;
	while (str[i] && str[i] != '.')
	{	
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}