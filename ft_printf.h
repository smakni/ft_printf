/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/06/25 23:05:03 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define conv 	"sSpdDioOuUxXcC"
#define HH		"hh"
#define LL		"ll"

#define OPTION	(str[i] == ' ' || str[i] == '#' || str[i] == '+' \
				|| str[i] == '-'|| str[i] == '0')


// une fonction d'analise de la conversion OK
// stockage dans structure OK
// fonction de conversion de la structure
// fonction pour check error
// \> sous fonction pour chaque flag > modif du res de la structure petit
// a petit > 
// affichage de res

// pour conversion_d
// faire fonction pour chaque cas, ex: 23.32d / -23.3d / -4.d
// creer la chaine d'acceuil
// et ensuite inserer le nb
// combinaison
// I la taille de la chaine
// II la precision
// III les option
// iV le nb
// if (strchr(arg->str, '0') != 0)

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
void	ft_analyse(t_format *arg);
char	check_conv(char *str);
char 	*check_option(char *str);
int 	check_widht(char *str);
int		check_precision(char *str);
int 	check_str(char *str);
char	*check_size(char *str);
void 	ft_conversion(t_format *arg, va_list av);
void	conversion_d(t_format *arg, va_list av);
char	*conversion_d1(char *nb);
void	conversion_d2(t_format *arg, char *nb, int len_nb, int i);
void	conversion_d3(t_format *arg, char *nb, int len_nb, int i);
void	conversion_d4(t_format *arg, char *nb, int len_nb, int i);
void	conversion_s(t_format *arg, va_list av);
void	conversion_c(t_format *arg, va_list av);
void	ft_aff_param(t_format *arg);

#endif
