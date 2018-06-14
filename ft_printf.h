/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/06/14 12:07:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define conv 	"sSpdDioOuUxXcC"
#define flag 	"#0-+ "

#define OPTION	(str[i] == ' ' || str[i] == '#' || str[i] == '+' \
				|| str[i] == '-'|| str[i] == '0')

// une fonction d'analise de la conversion
// stockage dans structure
// fonction de conversion de la structure
// fonction d'affichage de la conversion

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
}				t_format;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void    *ft_memalloc(size_t size);
size_t  ft_strlen(const char *str);
char    *ft_itoa(int n);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int     ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strlen_c(const char *str, char c);
char	*ft_strcpy(char *dst, const char *src);

/*char	*ft_conv(char c, va_list av)
{
	t_format arg;
	char 	*str;
	char	*l;
	int		x;

	pf1 = &ft_putstr;
	if (c == 's')
	{
		str = va_arg(av, char *);
		return (str);
	}
	if (c == 'd')
	{
		x = va_arg(av, int);
		return (ft_itoa(x));
	}
	if (c == 'c')
	{
		l = va_arg(av, char *);
		return(l);
	}
	return(NULL);
}*/

#endif
