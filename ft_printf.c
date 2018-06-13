/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:45:26 by smakni            #+#    #+#             */
/*   Updated: 2018/06/13 15:24:55 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_check_conv(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && (ft_strchr(str, conv[j]) != 0))
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (NULL);
	return (&conv[j - 1]);
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

	i = 0;
	while (OPTION)
		i++;
	width = ft_atoi(ft_strsub(str, i, ft_strlen_c(str, '.')));
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
	precision = ft_atoi(ft_strsub(str, start, i));
	return (precision);
}

void	ft_analyse(t_format **arg)
{
	ft_putstr("ft_analyse = ");
	ft_putstr((*arg)->str);
	ft_putstr("\n--------\n");
	(*arg)->option = check_option((*arg)->str);
	ft_putstr("option = ");
	ft_putstr((*arg)->option);
	ft_putstr("\n--------\n");
	(*arg)->width = check_widht((*arg)->str);
	ft_putstr("width = ");
	ft_putnbr((*arg)->width);
	ft_putstr("\n--------\n");
	(*arg)->precision = check_precision((*arg)->str);
	ft_putstr("precision = ");
	ft_putnbr((*arg)->precision);
	ft_putstr("\n--------\n");
	/*(*arg)->size = check_size((*arg)->str);
	ft_putstr("size = ");
	ft_putstr((*arg)->size);
	ft_putstr("\n--------\n");*/
}

int		ft_printf(const char *format, ...)
{
	va_list 	av;
	char 		*tmp;
	int 		i;
	t_format 	*arg;

	tmp = (char *)format;
	va_start(av, format);
	i = 0;
<<<<<<< HEAD
	j = 0;
=======
>>>>>>> parent of 5528b42... fix multiple arg
	while (format[i])
	{
		if (format[i] == '%')
		{
<<<<<<< HEAD
			tmp = ft_strsub(tmp, ft_strlen_c(tmp, '%') + j, ft_strlen(tmp) - ft_strlen_c(tmp, '%'));
			arg->type = *ft_check_conv(tmp);
=======
			tmp = ft_strsub(tmp, ft_strlen_c(tmp, '%'), ft_strlen_c(format, '\0') - ft_strlen_c(format, '%'));
			arg->type = ft_check_conv(tmp);
>>>>>>> parent of 5528b42... fix multiple arg
			ft_putstr("\n--------\n");
			ft_putstr("type = ");
			ft_putchar(arg->type);
			ft_putstr("\n--------\n");
			arg->str = ft_strsub(tmp, ft_strlen_c(tmp, '%') + 1, ft_strlen_c(tmp, arg->type) - ft_strlen_c(tmp, '%'));
			ft_analyse(&arg);
<<<<<<< HEAD
			ft_putstr("============");
		}
		else 
=======
			i+= ft_strlen(arg->str);
		}
		else
>>>>>>> parent of 5528b42... fix multiple arg
			ft_putchar(format[i]);
		i++;
	}
	ft_putstr("END\n");
	va_end(av);
	return (i);
}
