/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:30:51 by smakni            #+#    #+#             */
/*   Updated: 2018/09/10 16:40:36 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putchar2(wint_t c)
{
    ft_putchar1((c >> 6) + 0xC0);
    ft_putchar1((c & 0x3F) + 0x80);
}
