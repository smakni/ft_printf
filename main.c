/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:00:23 by smakni            #+#    #+#             */
/*   Updated: 2018/06/08 16:12:42 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char *str;
	int x;

	x = 27;
	str = "sabri";
	ft_printf("salut je suis %s\nt'es sur ?\nOui c'est moi %s!\nOk et tu as quel age ?\nJ'ai %dans", str, str, x);
	return (0);
}
