/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/15 17:30:57 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char 	*str;
	int 	x;
	char 	c;

	x = 27;
	c = '!';
	str = "Sabri";
	//ft_putstr("ft_printf = ");
	ft_printf("j'ai %d ans et je m'appele %s%c", x, str, c);
	//ft_putstr("------------");
	//printf("printf= %d", x); 							
	//printf("\n%+2z3.4d", x);
	//printf("hello %s\n", str);
	return (0);
}
