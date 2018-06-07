/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:06:24 by smakni            #+#    #+#             */
/*   Updated: 2018/06/07 18:36:11 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h> 
#include <stdarg.h> 
#include <string.h> 

typedef enum {false, true} bool; 

/*SYSTEM*/ 

size_t _strlen(const char *str); 

/*PRINTF*/ 

typedef int (*p_func)(va_list); 

typedef enum 
{ 
	INT = 0, FLOAT, CHAR, STR, NB_FORMATS, NO_FORMAT 
} 		FORMATS_TOKEN; 

typedef struct s_Format 
{ 
	char token; 
	p_func func; 
	FORMATS_TOKEN next_format; 
}				Format;

typedef int (*p_func)(va_list); 

void ft_putchar(char c); 
void ft_putstr(char *str); 
void ft_putnbr(int nb); 
int affStr(va_list av); 
int affCh(va_list av); 
int affInt(va_list av); 

#endif
