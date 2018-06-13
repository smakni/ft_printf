/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/13 15:25:29 by smakni           ###   ########.fr       */
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
<<<<<<< HEAD
	ft_printf("aknd%#1651.1566chcoiuqhc%d", str);
=======
	ft_printf("hello %+5454.5485dblabla\n", str);
>>>>>>> parent of 5528b42... fix multiple arg
	//printf("hello %s\n", str);
	return (0);
}
