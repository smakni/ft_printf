/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/06/19 17:35:35 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define conv 	"sSpdDioOuUxXcC"
#define s_opt 	"-+#0 "

#define OPTION	(str[i] == ' ' || str[i] == '#' || str[i] == '+' \
				|| str[i] == '-'|| str[i] == '0')

#define OPTION_ARG ((*arg)->str[i] == ' ' || (*arg)->str[i] == '#' \
					|| (*arg)->str[i] == '+' || (*arg)->str[i] == '-' \
					|| (*arg)->str[i] == '0')

// une fonction d'analise de la conversion OK
// stockage dans structure OK
// fonction de conversion de la structure
// fonction pour check error
// \> sous fonction pour chaque flag > modif du res de la structure petit
// a petit > 
// affichage de res

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

//------ft_printf

int		ft_printf(const char *format, ...);
void	conversion_d(t_format **arg, va_list av);
void	conversion_s(t_format **arg, va_list av);
void	conversion_c(t_format **arg, va_list av);
char	check_conv(char *str);
char 	*check_option(char *str);
int 	check_widht(char *str);
int		check_precision(char *str);
int 	check_str(char *str);


//------libft

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
void    ft_strdel(char **as);
void    *ft_memset(void *b, int c, size_t len);

#endif
