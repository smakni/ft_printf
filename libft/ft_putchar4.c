/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:18:19 by smakni            #+#    #+#             */
/*   Updated: 2018/10/25 11:58:03 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar4(wchar_t c)
{
	ft_putchar1((c >> 18) + 0xF0);
	ft_putchar1(((c >> 12) & 0x3F) + 0x80);
	ft_putchar1(((c >> 6) & 0x3F) + 0x80);
	ft_putchar1((c & 0x3F) + 0x80);
}
