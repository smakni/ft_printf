/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/10/25 12:27:53 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned long long int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa_llui(unsigned long long int n)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = ft_size(n);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	while (size >= i)
	{
		str[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	return (str);
}
