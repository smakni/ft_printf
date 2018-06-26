/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/27 00:32:23 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char 	*str;
	char 	*test1;
	char	*test2;
	char	*test3;
	int 	x;
	char 	c;

	x = -25;
	c = '!';
	str = "Sabri";
	test1 = "j'ai %-14.2d ans et je m'appele %.8s%4c\n";
	test2 = "j'ai %-14.5d ans et je m'appele %.8s%4c\n";
	test3 = "j'ai %+-0134.5d ans et je m'appele %.8s%4c\n";
	ft_printf(">>>>>>>>>>>>>>>>>>>>ft_printf<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf(test1, x, str, c);
	ft_printf(test2, x, str, c);
	ft_printf(test3, x, str, c);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>printf<<<<<<<<<<<<<<<<<<<\n\n");
	printf(test1, x, str, c);
	printf(test2, x, str, c);
	printf(test3, x, str, c);
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
