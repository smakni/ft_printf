/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:01:25 by smakni            #+#    #+#             */
/*   Updated: 2018/10/31 18:54:10 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	setlocale(LC_ALL, "");
	int x;
	int y;
	//x = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//y = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	x = ft_printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	y = printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//ft_printf("%10p\n", 43);
	//printf("%10p\n", 43);
	printf("me = %d\ncp = %d\n", x, y);
	return (0);
}

