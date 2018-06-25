/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/24 16:56:34 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char 	*str;
	int 	x;
	char 	c;

	x = 25;
	c = '!';
	str = "Sabri";
	ft_printf("j'ai %d ans et je m'appele %s%c", x, str, c);
	//printf("j'ai %15.10d ans et je m'appele %2s%15c", x, str, c);
	//ft_printf("%.2s", str);
	//printf("%.2s", str);
	//ft_printf("%10.4d", x);
	//printf("%4.4d", x);
	//ft_putstr("------------\n");
	//printf("%5c", c); 							
	//printf("\n%+2z3.4d", x);
	//printf("hello %s\n", str);
	return (0);
}
