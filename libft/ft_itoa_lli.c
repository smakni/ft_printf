/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/07/20 18:11:25 by sabri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int		ft_size(long long int n)
{
	long long int size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char						*ft_itoa_lli(long long int n)
{
	char				*str;
	long long int		i;
	long long int		size;

	i = 0;
	size = ft_size(n);
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
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
