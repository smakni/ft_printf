/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/07/23 10:20:22 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define HH		"hh"
#define LL		"ll"
#define	OPT		" 0+-#"
#define CONV 	"sSpdDioOuUxXcC%%"

#define OPTION	(str[i] == ' ' || str[i] == '#' || str[i] == '+' \
				|| str[i] == '-'|| str[i] == '0')

typedef struct s_format
{
	char 	*str;	
	int		len;
	char	*option;
	int		width;
	int		precision;
	char	*size;
	char	type;
	char	*res;
	int		count;
}				t_format;

int		ft_printf(const char *format, ...);
void	ft_analyse(t_format *arg);
char	check_conv(const char *str, int x);
char 	*check_option(char *str);
int 	check_widht(char *str);
int		check_precision(char *str);
int 	check_str(char *str);
char	*check_size(char *str);
void 	ft_conversion(t_format *arg, va_list av);
void	conversion_d(t_format *arg, va_list av);
char	*conversion_d0(t_format *arg, char *nb, va_list av);
char	*conversion_d1(t_format *arg, char *nb);
char 	*conversion_d2(t_format *arg, char *nb);
void	conversion_d3(t_format *arg, char *nb, int i, int len_nb);
void	conversion_d4(t_format *arg, char *nb, int len_nb, int i);
void	conversion_s(t_format *arg, va_list av);
char	*conversion_s1(t_format *arg, char *tmp);
char	*conversion_s2(t_format *arg, char *tmp, int len, int i);
void	conversion_c(t_format *arg, va_list av);
void	conversion_p(t_format *arg, va_list av);
void	conversion_x(t_format *arg, va_list av);
void	conversion_X(t_format *arg, va_list av);
void	conversion_o(t_format *arg, va_list av);
void	conversion_0(t_format *arg);
void	ft_aff_param(t_format *arg);

#endif
