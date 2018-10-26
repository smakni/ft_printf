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

static void	*ft_join_malloc(void *s1, void const *s2, size_t n1, size_t n2)
{
	char	*str;

	str = NULL;
	if (!s1 && !s2)
		return (str);
	else if (s1 && !s2)
	{
		str = (char*)malloc(sizeof(char) * n1);
		if (str)
			return (ft_memcpy(str, s1, n1));
	}
	else if (!s1 && s2)
	{
		str = (char*)malloc(sizeof(char) * n2);
		if (str)
			return (ft_memcpy(str, s2, n2));
	}
	return (str);
}

void		*ft_memjoin(void *s1, void const *s2, size_t n1, size_t n2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		str = (char*)malloc(sizeof(char) * (n1 + n2));
		if (str)
		{
			while (j < n1)
				*((char*)str + i++) = *((char*)s1 + j++);
			j = 0;
			while (j < n2)
				*((char*)str + i++) = *((char*)s2 + j++);
		}
	}
	else
		str = ft_join_malloc(s1, s2, n1, n2);
	return (str);
}
/*
void	*ft_memjoin(void *s1, const void *s2, size_t n1, size_t n2)
{
	void	*res;

	if (!s1 || n1 == 0)
		s1 = ft_memalloc(1);
	if (!(res = ft_memalloc(n1 + n2)))
		return (0);
	res = ft_memcpy(res, s1, n1);
	res = ft_memcpy_from(res, s2, n1, n2);
	return (res);
}*/
