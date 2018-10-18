/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 10:19:01 by smakni            #+#    #+#             */
/*   Updated: 2018/10/18 14:06:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memjoin(void *s1, const void *s2, size_t n1, size_t n2)
{
	void	*res;

	if (!(res = ft_memalloc(n1 + n2 + 1)))
		return (0);
	res = ft_memcpy(res, s1, n1);
	res = ft_memcpy_from(res, s2, n1, n2);
	return (res);
}
