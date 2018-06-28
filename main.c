/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/28 15:18:41 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char 	*str;
	char 	*test1;
	char	*test2;
	char	*test3;
	char 	*test4;
	char	*test5;
	char	*test6;
	char	*test7;
	int 	x;
	char 	c;

	x = +25;
	c = '!';
	str = "Sabri";
	test1 = "(1)j'ai %14.2d ans et je m'appele %9.9s%4c\n";
	test2 = "(2)j'ai %-14.5d ans et je m'appele %5.5s%.4c\n";
	test3 = "(3)j'ai %-07.4d ans et je m'appele %-s%0c\n";
	test4 = "(4)j'ai %-014d ans et je m'appele %0.8s%4c\n";
	test5 = "(5)j'ai %-5d ans et je m'appele %.2s%.4c\n";
	test6 = "(6)j'ai %+7.4d ans et je m'appele %010.2s%0c\n";
	test7 = "(7)j'ai %+7.4d ans et je m'appele %-010.2s%0c\n";
	ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>FT_PRINTF<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf(test1, x, str, c);
	ft_printf(test2, x, str, c);
	ft_printf(test3, x, str, c);
	ft_printf(test4, x, str, c);
	ft_printf(test5, x, str, c);
	ft_printf(test6, x, str, c);
	ft_printf(test7, x, str, c);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>PRINTF<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf(test1, x, str, c);
	printf(test2, x, str, c);
	printf(test3, x, str, c);
	printf(test4, x, str, c);
	printf(test5, x, str, c);
	printf(test6, x, str, c);
	printf(test7, x, str, c);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>RESULT<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	return (0);
}
