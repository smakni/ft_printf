/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/19 21:27:55 by smakni           ###   ########.fr       */
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
	ft_printf("j'ai %025d ans et je m'appele %s%2c", x, str, c);
	//ft_printf("%05c", c);
	//ft_putstr("------------\n");
	//printf("%5c", c); 							
	//printf("\n%+2z3.4d", x);
	//printf("hello %s\n", str);
	return (0);
}
