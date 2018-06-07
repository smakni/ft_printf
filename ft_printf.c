/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:02:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/07 18:38:17 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool is_Token(char token, char c) { if (c == token) return true; return false; }
bool is_Format(size_t bool_format) { if (bool_format != true) return true; return false; } 

char get_Integer() { return 'd'; } 
char get_Char() { return 'c'; } 
char get_String() { return 's'; } 

p_func get_IntAFF()	{ return affInt; }
p_func get_ChAFF()	{ return affCh; }
p_func get_StrAFF()	{ return affStr; }

// Machine à état ----------------------------------------

void	init_ListFormat_Token(Format list_format[NB_FORMATS])
{	
	list_format[INT].token = get_Integer();
	list_format[CHAR].token = get_Char();
	list_format[STR].token = get_String();

	list_format[INT].next_format = CHAR;
	list_format[CHAR].next_format = STR;
	list_format[STR].next_format = NO_FORMAT;

	list_format[INT].func = get_IntAFF();
	list_format[CHAR].func = get_ChAFF();
	list_format[STR].func = get_StrAFF();
}

void	formatCmp(va_list av, char c)
{
	size_t check_format = false;
	Format list_format[NB_FORMATS];
	
	init_ListFormat_Token(list_format);
	FORMATS_TOKEN current_format = INT;
	while (current_format != NO_FORMAT)
	{
		if (list_format[current_format]. token == c)
		{
			list_format[current_format].func(av);
			check_format = true;
		}
		current_format = list_format[current_format].next_format;
	}
	if (is_Format(check_format) == true)
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}

// fin machine à état ---------------------------------------

void	ft_printf(char *str, ...)
{
	va_list av;
	size_t i;

	i = 0;
	va_start(av, str);
	while (str[i])
	{
		if (is_Token('%', str[i]) == true)
			formatCmp(av, str[++i]);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(av);
	ft_putchar('\n');
}
