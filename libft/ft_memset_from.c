/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_from.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:26:20 by smakni            #+#    #+#             */
/*   Updated: 2018/06/22 12:23:32 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset_from(void *b, size_t start, int c, size_t len)
{
	size_t				i;
	unsigned char		*tmp;

	tmp = (unsigned char *)b;
	i = 0;
	while (i < start)
		i++;
	while (i < (start + len))
	{
		tmp[start + i] = (unsigned char)c;
		i++;
	}
	return (b);
}
