/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:55:45 by smakni            #+#    #+#             */
/*   Updated: 2018/10/20 17:56:19 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    int x;
    char y;
	wchar_t s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	//x = ft_printf("%-12i", 0); error
	x  = ft_printf("MOI=%S", s);
	ft_printf("\n");
	y = printf("\nCP=%S", s);
	//ft_putnbr(ft_printf("%C", 0x81000));
	ft_putnbr(x);
	ft_putchar('/');
	ft_putnbr(y);

}
