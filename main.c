/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/15 01:49:14 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char *str;
	int x;
	char l;

	x = 27;
	l = '?';
	str = "world";
	//ft_putstr("main = ");
	//ft_printf("bld%+0382a428.4702udda%Ucbla%01cbla%cbla%c", str, x, str);
	printf("\n%+2.4d", x);
	printf("\n%+2z3.4d", x);
	//printf("hello %s\n", str);
	return (0);
}
