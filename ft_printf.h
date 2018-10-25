/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/10/25 17:09:02 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <wchar.h>
# include <locale.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <inttypes.h>

# define HH		"hh"
# define LL		"ll"
# define OPT	" 0+-#"
# define CONV 	"sSpdDioOuUxXcC%%"

typedef struct	s_format
{
	char	*str;
	int		len;
	char	*option;
	int		width;
	int		precision;
	char	*size;
	char	type;
	char	*res;
	int		check;
	int		count;
	int		save;
}				t_format;

typedef struct s_control
{
	int		i;
	int		ret;
	int		len;
	char	*result;
}				t_control;

int				ft_printf(const char *format, ...);
void			ft_analyse(t_format *arg);
char			check_conv(const char *str, int x);
char			*check_option(char *str);
int				check_widht(char *str);
int				check_precision(char *str);
int				check_str(char *str);
char			*check_size(char *str);
void			ft_conversion(t_format *arg, va_list av);
void			conversion_d(t_format *arg, va_list av);
int				conversion_null(t_format *arg, char *nb);
char			*conversion_d0(t_format *arg, char *nb, va_list av);
char			*conversion_d0_d(t_format *arg, char *nb, va_list av);
char			*conversion_d0_u(t_format *arg, char *nb, va_list av);
char			*conversion_d0_o(t_format *arg, char *nb, va_list av);
char			*conversion_d0_x(t_format *arg, char *nb, va_list av);
char			*conversion_x1(t_format *arg, char *nb);
char			*conversion_d1(t_format *arg, char *nb);
char			*conversion_d2(t_format *arg, char *nb);
char			*conversion_d2x(t_format *arg, char *nb);
void			conversion_d3(t_format *arg, char *nb, int len_nb);
void			conversion_d4(t_format *arg);
void			conversion_s(t_format *arg, va_list av);
char			*conversion_s1(t_format *arg, char *tmp);
char			*conversion_s2(t_format *arg, char *tmp, int len, int i);
char			*conversion_bs(t_format *arg, va_list av);
void			conversion_c(t_format *arg, va_list av);
void			conversion_p(t_format *arg, va_list av);
void			conversion_x(t_format *arg, va_list av);
void			conversion_bx(t_format *arg, va_list av);
void			conversion_o(t_format *arg, va_list av);
void			conversion_0(t_format *arg);
void			ft_aff_param(t_format *arg);
char			*ft_strcpy_from(char *dst, const char *src, int start);
char			*ft_putchar_printf(wchar_t c, char *str, int check);

#endif
