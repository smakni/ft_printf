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
//  ft_printf("%X", -42);
//  ft_printf("\n");
//    printf("%X", -42);
//ft_printf("\n");
//  ft_printf("%lX", 4294967296);
//  ft_printf("\n");
//  printf("%lX", 4294967296);
//ft_printf("\n");
//  ft_printf("@moulitest: %s", NULL);
//  ft_printf("\n");
//    printf("@moulitest: %s", NULL);
/*ft_printf("\n");
  ft_printf("%s %s", NULL, "string");
  ft_printf("\n");
    printf("%s %s", NULL, "string");
ft_printf("\n");
  ft_printf("@moulitest: %5.o %5.0o", 0, 0);
  ft_printf("\n");
    printf("@moulitest: %5.o %5.0o", 0, 0);
ft_printf("\n");
  ft_printf("%hd", 32768);
  ft_printf("\n");
    printf("%hd", 32768);
ft_printf("\n");
  ft_printf("%hhd", 128);
  ft_printf("\n");
    printf("%hhd", 128);
ft_printf("\n");
  ft_printf("%hhd", -129);
  ft_printf("\n");
    printf("%hhd", -129);
ft_printf("\n");
  ft_printf("%lld", -9223372036854775808);
  ft_printf("\n");
    printf("%lld", -9223372036854775808);
ft_printf("\n");
  ft_printf("%jd", -9223372036854775808);
  ft_printf("\n");
    printf("%jd", -9223372036854775808);
ft_printf("\n");
  ft_printf("%zd", -1);
  ft_printf("\n");
    printf("%zd", -1);
ft_printf("\n");
  ft_printf("%+10.5d", 4242);
  ft_printf("\n");
    printf("%+10.5d", 4242);
ft_printf("\n");
  ft_printf("%-+10.5d", 4242);
    printf("%-+10.5d", 4242);
ft_printf("\n");
  ft_printf("%03.2d", -1);
    printf("%03.2d", -1);
ft_printf("\n");
  ft_printf("% u", 4294967295);
    printf("% u", 4294967295);
ft_printf("\n");
  ft_printf("%+u", 4294967295);
    printf("%+u", 4294967295);
ft_printf("\n");
  ft_printf("%hU", 4294967296);
    printf("%hU", 4294967296);

*/

//ft_putnbr(ft_printf("%c", -21));
//ft_putchar('\n');
//ft_putnbr(printf("%c", -21));

ft_putnbr(ft_printf("TEST : %lc", (wint_t)-21));
ft_putchar('\n');
ft_putnbr(printf("TEST : %lc", (wint_t)-21));
}