/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/07/18 15:09:27 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char 	*test1;
	char	*test2;
	char	*test3;
	char 	*test4;
	char	*test5;
	char	*test6;
	char	*test7;
	char	*test8;
	char	*test9;
	char	*test10;
	char	*test11;
	char	*test12;
	char	*test13;
	char	*test14;
	char	*test15;
	char	*test16;
	char	*test17;
	char	*test18;
	char	*test19;
	char	*test20;
	char 	*str;
	int 	x;
	char 	c;
	unsigned int ux;

	ux = 42;
	x = -42;
	c = '!';
	str = "Sabri";
	test1 = "(1)%1.4dblabla%s%c\n";
	test2 = "(2)%-14.5d\n";
	test3 = "(3)%+05d\n";
	test4 = "(4)%-014d\n";
	test5 = "(5)%-5d\n";
	test6 = "(6)%+7.4d\n";
	test7 = "(7)%s\n";
	test8 = "(8)adresse de str = %p\n";
	test9 = "(9)%x\n";
	test10 = "(10)%p\n";
	test11 = "(11)salut%10d\n";
	test12 = "(12)%010c\n";
	test13 = "(13)%o\n";
	test14 = "(14)%                   0-10%d\n";
	test15 = "(15)%                   010%d\n";
	test16 = "(16)%%\n";
	test17 = "(17)% 10.5%d\n";
	test18 = "salut%10.5dhello%10c%010%%%%%%dend\n";
	test19 = "(19)%ld\n";
	test20 = "(20)%X\n";
	ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>FT_PRINTF<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf(test1, x, str, c);
	ft_printf(test2, x);
	ft_printf(test3, x);
	ft_printf(test4, x);
	ft_printf(test5, x);
	ft_printf(test6, x);
	ft_printf(test7, str);
	ft_printf(test8, str);
	ft_printf(test9, ux);
	ft_printf(test10, str);
	ft_printf(test11, x);
	ft_printf(test12, c);
	ft_printf(test13, ux);
	ft_printf(test14, x);
	ft_printf(test15, x);
	ft_printf(test16, x);	
	ft_printf(test17, x);
	ft_printf(test18, x, c, x);
	ft_printf(test19, x);
	ft_printf(test20, ux);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>PRINTF<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf(test1, x, str, c);
	printf(test2, x);
	printf(test3, x);
	printf(test4, x);
	printf(test5, x);
	printf(test6, x);
	printf(test7, str);
	printf(test8, str);
	printf(test9, ux);
	printf(test10, str);
	printf(test11, x);
	printf(test12, c);
	printf(test13, ux); 
	printf(test14, x);
	printf(test15, x);
	printf(test16, x);
	printf(test17, x);
	printf(test18, x, c, x);
	printf(test19, x);
	printf(test20, ux);
/*	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>RETURN<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>FT_PRINTF<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf("ret = ");
	ft_printf("%d\n", ft_printf(test1, x, str, c));
	ft_printf("ret = ");
	ft_printf("%d\n", ft_printf(test8, str));
	ft_printf("ret = ");
	ft_printf("%d\n", ft_printf(test12, c));
	ft_printf("ret = ");
	ft_printf("%d\n", ft_printf(test13, ux));
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>PRINTF<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf("ret = ");
	ft_printf("%d\n", printf(test1, x, str, c));
	ft_printf("ret = ");
	ft_printf("%d\n", printf(test8, str));
	ft_printf("ret = ");
	printf("%d\n", printf(test12, c));
	ft_printf("ret = ");
	printf("%d\n", printf(test13, ux));
	return (0);*/
}
