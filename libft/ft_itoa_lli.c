/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/10/30 15:46:50 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int		ft_size(unsigned long long int n)
{
	long long int size;

	size = 0;
	if (n == 0)
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
	unsigned long long	tmp_n;
	char				*str;
	long long int		i;
	long long int		size;
	int					sign;

	sign = 0;
	i = 0;
	size = 0;
	if (n < 0)
	{
		sign = -1;	
		tmp_n = (unsigned long long)-n;
		size++;
	}
	else
		tmp_n = (unsigned long long)n;
	size += ft_size(tmp_n);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	if (sign == -1)
	{
		str[i] = '-';
		i++;
	}
	while (size >= i)
	{
		str[size] = (tmp_n % 10) + '0';
		tmp_n /= 10;
		size--;
	}
	return (str);
}
