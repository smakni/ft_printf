/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:55:45 by smakni            #+#    #+#             */
/*   Updated: 2018/09/14 16:16:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main()
{
    int x;
    char y;
    setlocale(LC_ALL, "");

ft_printf(">>>[%d]", ft_printf("TEST(1) : %lc", 0x40501));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(2) : %C", 0xbffe));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(3) : %C", (wint_t)-2));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(4) : %lc", 254));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(5) : %C", 256));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(6) : %8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(7) : %---8C et coco %1C titi", 3250, 0xffff));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(8) : %6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
ft_printf("\n");
ft_printf(">>>[%d]", ft_printf("TEST(9) : yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));
ft_printf("\n");
ft_printf("-------------------------------------------------------------");
printf("\n");
printf(">>>[%d]", printf("TEST(1) : %lc", 0x40501));
printf("\n");
printf(">>>[%d]", printf("TEST(2) : %C", 0xbffe));
printf("\n");
printf(">>>[%d]", printf("TEST(3) : %C", (wint_t)-2));
printf("\n");
printf(">>>[%d]", printf("TEST(4) : %lc", 254));
printf("\n");
printf(">>>[%d]", printf("TEST(5) : %C", 256));
printf("\n");
printf(">>>[%d]", printf("TEST(6) : %8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
printf("\n");
printf(">>>[%d]", printf("TEST(7) : %---8C et coco %1C titi", 3250, 0xffff));
printf("\n");
printf(">>>[%d]", printf("TEST(8) : %6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
printf("\n");
printf(">>>[%d]", printf("TEST(9) : yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));

}

