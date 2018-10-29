/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:03:20 by smakni            #+#    #+#             */
/*   Updated: 2018/10/25 12:30:57 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned long long int n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		size++;
	}
	return (size);
}

static char 	*get_base(int l, int f)
{
	char *tmp;
	char *base;

	base = NULL;
	if (f == 0)
		tmp = "0123456789abcdef";
	else
		tmp = "0123456789ABCDEF";
	if (l > 9)
		base = ft_strsub(tmp, 0, l);
	else
		base = ft_strdup(tmp);
	return (base);
}

char			*ft_itoa_base_llui(unsigned long long int n, int l, int f)
{
	char	*str;
	int		size;
	char	*base;

	base = get_base(l, f);
	size = ft_size(n, l);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	str[size] = '\0';
	size--;
	while (size >= 0)
	{
		str[size] = base[n % l];
		n /= l;
		size--;
	}
	ft_strdel(&base);
	return (str);
}
