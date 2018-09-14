/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:48:11 by smakni            #+#    #+#             */
/*   Updated: 2018/09/14 16:19:17 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar_printf(wint_t c, t_format *arg)
{
    if (c < 0)
    {
        arg->count = -1;
        return ;
    }
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
    else if ((c >= 65536 && c <= 131069) || (c >= 131072 && c <= 196605) 
                || (c >= 196607 && c <= 983037) 
                || (c >= 983040 && c <= 1048573)
                || (c >= 1048576 && c <= 1114109))
    {
        arg->count += 3;
        ft_putchar4(c);
    }
    else
        arg->count = -1;
}
