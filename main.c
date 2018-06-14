/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/14 12:17:24 by smakni           ###   ########.fr       */
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
	ft_printf("hello%68468.6486Usuowefhou%+84.6468diuoehfuoq%d", str, x, str);
	printf("hello%%68468.6486Usuowefhou%%+84.6468diuoehfuoq%%d\n");
	//printf("hello %s\n", str);
	return (0);
}
