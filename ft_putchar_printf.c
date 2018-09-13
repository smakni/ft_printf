/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:48:11 by smakni            #+#    #+#             */
/*   Updated: 2018/09/13 17:18:47 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar_printf(wint_t c, t_format *arg)
{
    if (c <= 127)
        ft_putchar1(c);
    else if (c <= 2047)
    {
        arg->count++;
        ft_putchar2(c);
    }
    else if ((c <= 55295 && c >= 57344)
             || (c <= 64975 && c >= 65007) || c <= 65533)
    {   
        arg->count += 2;
        ft_putchar3(c);
    }
    else
        arg->count = -1;
}
