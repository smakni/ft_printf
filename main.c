/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/08/09 17:36:38 by smakni           ###   ########.fr       */
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
	char	*test21;
	char	*test22;
	char	*test23;
	char	*test24;
	char	*test25;
	char	*test26;
	char	*test27;
	char	*test28;
	char	*test29;
	char	*test30;
	char	*test31;
	char	*test32;
	char 	*str;
	int 	x;
	char 	c;
	unsigned int ux;

	ux = 4347727;
	x = 0;
	c = 'a';
	str = "Sabri";
	test1 = "(1)toto%   .0D !!!\n";
	test2 = "(2)%-14.5d\n";
	test3 = "(3)%+ 05d\n";
	test4 = "(4)%-014d\n";
	test5 = "(5)%-10.5d\n";
	test6 = "(6)%+010.4d\n";
	test7 = "(7)%s\n";
	test8 = "(8)adresse de str = %p\n";
	test9 = "(9)%20p\n";
	test10 = "(10)%#o\n";
	test11 = "(11)salut%10d\n";
	test12 = "(12)%010c\n";
	test13 = "(13)%o\n";
	test14 = "(14)%                   0-10%d\n";
	test15 = "(15)%                   010%d\n";
	test16 = "(16)%%\n";
	test17 = "(17)% 10.5%d\n";
	test18 = "(18)salut%+10.5dhello%10c%010%%%%%%dend\n";
	test19 = "(19)%D\n";
	test20 = "(20)%#20.7x\n";
	test21 = "(21)\n%024hho et%#1.2o %012.26O\n";
	test22 = "(22)%#.22zX et %020.14jx\n";
	test23 = "(23)coco et %-#-#--24O titi%#012o\n";
	test24 = "(24)toto %###.0o%#.O et %#.1o !\n";
	test25 = "(25)t %#7.5X%0006.2x et %lX!\n";
	test26 = "(26)%011X\n";
	test27 = "(27)toto %0##0.4X%#4.2xet c'est fini \n";
	test28 = "(28)%0#10.x %0#x\n";
	test29 = "(29)%011X\n";
	test30 = "(30)%#025X\n";
	test31 = "(31)cc%#.4X et %#0012x %#04hX !!\n";
	test32 = "(32)%0#10.0x\n";
	ft_printf(">>>>>>>>>>>>>>>>>>>>>>>>FT_PRINTF<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	ft_printf(test1, x);
	ft_printf(test2, x);
	ft_printf(test3, x);
	ft_printf(test4, x);
	ft_printf(test5, x);
	ft_printf(test6, x);
	ft_printf(test7, str);
	ft_printf(test8, str);
	ft_printf(test9, str);
	ft_printf(test10, str);
	ft_printf(test11, x);
	ft_printf(test12, c);
	ft_printf(test13, x);
	ft_printf(test14, x);
	ft_printf(test15, x);
	ft_printf(test16, x);	
	ft_printf(test17, x);
	ft_printf(test18, x, c, x);
	ft_printf(test19, 280452758896520);
	ft_printf(test20, ux);
	ft_printf(test21, (unsigned char)12, 0, 123654789);
	ft_printf(test22, 0xff1144ff1144, 0xffaabbccee);
	ft_printf(test23, 12, -874);
	ft_printf(test24, 0, 0, 0);
	ft_printf(test25, 0xab, 0x876, 0xff11ff11ff1);
	ft_printf(test26, 0xdd66);
	ft_printf(test27, 0x037a, 0x9e);
	ft_printf(test28, 12345, 0);
	ft_printf(test29, 0xdd66);
	ft_printf(test30, 0xff7744);
	ft_printf(test31, 0xaef, 0xe, (unsigned short)0);
	ft_printf(test32, 0);
	printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>PRINTF<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
	printf(test1, x, x, x);
	printf(test2, x);
	printf(test3, x);
	printf(test4, x);
	printf(test5, x);
	printf(test6, x);
	printf(test7, str);
	printf(test8, str);
	printf(test9, str);
	printf(test10, str);
	printf(test11, x);
	printf(test12, c);
	printf(test13, x); 
	printf(test14, x);
	printf(test15, x);
	printf(test16, x);
	printf(test17, x);
	printf(test18, x, c, x);
	printf(test19, 0xff11ff11ff88);
	printf(test20, ux);
	printf(test21, (unsigned char)12, 0, 123654789);
	printf(test22, 0xff1144ff1144, 0xffaabbccee);
	printf(test23, 12, -874);
	printf(test24, 0, 0, 0);
	printf(test25, 0xab, 0x876, 0xff11ff11ff1);
	printf(test26, 0xdd66);
	printf(test27, 0x037a, 0x9e);
	printf(test28, 12345, 0);
	printf(test29, 0xdd66);
	printf(test30, 0xff7744);
	printf(test31, 0xaef, 0xe, (unsigned short)0);
	printf(test32, 0);
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
