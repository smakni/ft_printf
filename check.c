/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:19:57 by smakni            #+#    #+#             */
/*   Updated: 2018/10/30 12:19:48 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_conv(const char *str, int x)
{
	int	j;

	j = 0;
	x++;
	if (str[x] == CONV[j])
		return (CONV[j]);
	while (str[x])
	{
		if (str[x] != CONV[j])
		{
			j = 0;
			while (CONV[j] && str[x] != CONV[j])
				j++;
			if (str[x] == CONV[j])
				return (CONV[j]);
		}
		x++;
	}
	return ('0');
}

char	*check_option(char *str)
{
	int		i;
	int		j;
	char	*opt;
	char	*tmp;

	i = 0;
	j = 0;
	opt = NULL;
	tmp = NULL;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0')
		i++;
	tmp = ft_strsub(str, 0, i);
	opt = ft_memalloc(i + 1);
	i = 0;
	j = 0;
	while (OPT[i])
	{
		if (ft_strchr(tmp, OPT[i]) != 0)
			opt[j++] = OPT[i];
		i++;
	}
	ft_strdel(&tmp);
	return (opt);
}

int		check_widht(char *str)
{
	int		i;
	int		width;
	char	*tmp;

	i = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0')
		i++;
	if (ft_strchr(str, '.') != 0)
		tmp = ft_strsub(str, i, ft_strlen_c(str, '.'));
	else
		tmp = ft_strsub(str, i, ft_strlen(str) - i);
	width = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (width);
}

int		check_precision(char *str)
{
	int		i;
	char	*tmp;
	int		start;
	int		precision;

	i = 0;
	start = 0;
	if (ft_strchr(str, '.') == 0)
		return (0);
	while (str[start] != '.')
		start++;
	start++;
	if (str[start + 1] < '0' && str[start + 1] > '9')
		return (1);
	while (str[start + i] >= '0' && str[start + i] <= '9')
		i++;
	tmp = ft_strsub(str, start, i);
	precision = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (precision);
}

int		check_str(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0')
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

char	*check_size(char *str)
{
	if (ft_strstr(str, HH) != 0)
		return (HH);
	else if (ft_strstr(str, LL) != 0)
		return (LL);
	if (ft_strchr(str, 'l') != 0)
		return ("l");
	else if (ft_strchr(str, 'h') != 0)
		return ("h");
	else if (ft_strchr(str, 'j') != 0)
		return ("j");
	else if (ft_strchr(str, 'z') != 0)
		return ("z");
	return ("");
}
