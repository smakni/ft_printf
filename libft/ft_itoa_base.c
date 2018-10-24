/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/10/24 16:50:40 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base(int n, int len, int flag)
{
	char	*str;
	int		i;
	int		size;
	char 	*base;

	i = 0;
	if (flag == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (len > 9)
		base = ft_strsub(base, 0, len);
	size = ft_size(n, len);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	while (size >= i)
	{
		str[size] = base[n % len];
		n /= len;
		size--;
	}
	return (str);
}