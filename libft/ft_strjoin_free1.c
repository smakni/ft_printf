/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:12:17 by smakni            #+#    #+#             */
/*   Updated: 2018/11/13 18:16:33 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free1(char *s1, char *s2)
{
	char	*str_joined;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str_joined = malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	while (s1[i])
	{
		str_joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_joined[i + j] = s2[j];
		j++;
	}
	str_joined[len] = '\0';
	ft_strdel(&s1);
	return (str_joined);
}
