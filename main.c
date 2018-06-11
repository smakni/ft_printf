/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/11 20:03:00 by sabri            ###   ########.fr       */
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
	str = "sabri";
	ft_printf("salut je suis %s\nt'es sur ?\nOui c'est moi %s!\nOk et tu as quel age %c\nJ'ai %dans", str, str, l, x);
	return (0);
}
