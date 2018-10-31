/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:19:57 by smakni            #+#    #+#             */
/*   Updated: 2018/10/31 18:54:07 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_conv(const char *str, int x)
{
	int	j;
	char *check_str;

	j = 0;
	check_str = "0123456789 +-#hljz.";
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
			else if (ft_strchr(check_str, str[x]) == 0)
				return (str[x]);
		}
		x++;
	}
	return ('0');
}

int		check_opt_0(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] == '0' && ft_isdigit(str[i - 1]) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*check_option(char *str)
{
	int i;
	int j;
	int check;
	char *opt;
	
	i = -1;
	j = 0;
	opt = NULL;
	check = check_opt_0(str);
	while (OPT[++i])
		if (ft_strchr(str, OPT[i]) != 0)
			j++;
	if (!(opt = ft_memalloc(j + check)))
		return (NULL);
	i = -1;
	j = 0;
	while (OPT[++i])
		if (ft_strchr(str, OPT[i]) != 0)
			opt[j++] = OPT[i];
	if (check == 1)
		opt[j] = '0';
	return (opt);
}

int		check_widht(char *str)
{
	int		i;
	int		width;
	char	*tmp;

	i = 0;
	while (str[i] == ' ' || str[i] == '#' || str[i] == '+' || str[i] == '-'
			|| str[i] == '0' || str[i] == 'h' || str[i] == 'l' || str[i] == 'j'
			|| str[i] == 'z')
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
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{	
		if (str[i] == 'h')
			count++;
		i++;
	}
	if (ft_strchr(str, 'l') != 0 || ft_strchr(str, 'j') != 0 
			|| ft_strchr(str, 'z') != 0)
		return ("l");
	else if (count >= 2)
		return ("hh");
	else if (count == 1)
		return("h");
	return ("");
}
