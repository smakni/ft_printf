/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:48:17 by smakni            #+#    #+#             */
/*   Updated: 2018/06/11 23:20:21 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define conv 	"sSpdDioOuUxXcC"
#define flag 	"#0-+ hhlljz"

// une fonction d'analise de la conversion
// stockage dans structure
// fonction de conversion de la structure
// fonction d'affichage de la conversion

typedef struct s_format
{
	char 	*str;
	int		len;
	void	*pf;
}				t_format;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void    *ft_memalloc(size_t size);
size_t  ft_strlen(const char *str);
char    *ft_itoa(int n);

#endif
