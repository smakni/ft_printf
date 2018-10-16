/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:49:10 by smakni            #+#    #+#             */
/*   Updated: 2018/05/16 12:56:40 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		x = i * i;
		if (x == nb)
			return (i);
		i++;
	}
	return (0);
}
