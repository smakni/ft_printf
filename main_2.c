/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:55:45 by smakni            #+#    #+#             */
/*   Updated: 2018/10/24 14:24:26 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    int x;
    char y;
	wchar_t s[4];

//	setlocale(LC_ALL, "");
	s[0] = 'S';
	s[1] = 256;
	s[2] = 'u';
	s[3] = '\0';
	ft_printf("MOI(1) : %0#10.0x\n", 0);
	ft_printf("CP(2) : %#04hX\n", (unsigned short)0);
	printf("MOI(1) : %0#10.0x\n", 0);
	printf("CP(2) : %#04hX\n", (unsigned short)0);
}
