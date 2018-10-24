/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_d0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabri <sabri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 12:33:02 by sabri             #+#    #+#             */
/*   Updated: 2018/10/24 16:37:36 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion_d0(t_format *arg, char *nb, va_list av)
{
	if (arg->type == 'd' || arg->type == 'D' || arg->type == 'i')
		nb = conversion_d0_d(arg, nb, av);
	else if (arg->type == 'u' || arg->type == 'U')
		nb = conversion_d0_u(arg, nb, av);
	else if (arg->type == 'o' || arg->type == 'O')
		nb = conversion_d0_o(arg, nb, av);
	else if (arg->type == 'x' || arg->type == 'X')
		nb = conversion_d0_x(arg, nb, av);
	return (nb);
}

char	*conversion_d0_d(t_format *arg, char *nb, va_list av)
{
	if ((arg->size[0] == '\0' && arg->type != 'D')
			|| (ft_strcmp(arg->size, "h") == 0)
			|| (ft_strcmp(arg->size, "hh") == 0))
		nb = ft_itoa(va_arg(av, int));
	else if (arg->type == 'D' || (ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_li(va_arg(av, long int));
	else if (ft_strcmp(arg->size, "ll") == 0)
		nb = ft_itoa_lli(va_arg(av, long long int));
	else if (ft_strcmp(arg->size, "j") == 0)
		nb = ft_itoa_imax(va_arg(av, intmax_t));
	else if (ft_strcmp(arg->size, "z") == 0)
		nb = ft_itoa_it(va_arg(av, size_t));
	return (nb);
}

char	*conversion_d0_u(t_format *arg, char *nb, va_list av)
{
	if ((arg->size[0] == '\0' && arg->type != 'U')
			|| (ft_strcmp(arg->size, "h") == 0)
			|| (ft_strcmp(arg->size, "hh") == 0))
		nb = ft_itoa_ui(va_arg(av, unsigned int));
	else if (arg->type == 'U' || (ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_lui(va_arg(av, unsigned long int));
	else if (ft_strcmp(arg->size, "ll") == 0)
		nb = ft_itoa_llui(va_arg(av, unsigned long long int));
	else if (ft_strcmp(arg->size, "j") == 0)
		nb = ft_itoa_uit(va_arg(av, uintmax_t));
	else if (ft_strcmp(arg->size, "z") == 0)
		nb = ft_itoa_it(va_arg(av, size_t));
	return (nb);
}

char	*conversion_d0_o(t_format *arg, char *nb, va_list av)
{
	if ((arg->size[0] == '\0' && arg->type != 'O')
		|| (ft_strcmp(arg->size, "h") == 0)
		|| (ft_strcmp(arg->size, "hh") == 0))
		nb = ft_itoa_base_ui(va_arg(av, unsigned int), 8, 0);
	else if (arg->type == 'O' || (ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_base_lui(va_arg(av, unsigned long int), 8, 0);
	else if (ft_strcmp(arg->size, "ll") == 0)
		nb = ft_itoa_base_llui(va_arg(av, unsigned long long int), 8, 0);
	else if (ft_strcmp(arg->size, "j") == 0)
		nb = ft_itoa_base_uit(va_arg(av, uintmax_t), 8, 0);
	else if (ft_strcmp(arg->size, "z") == 0)
		nb = ft_itoa_base_it(va_arg(av, size_t), 8, 0);
	return (nb);
}

char	*conversion_d0_x(t_format *arg, char *nb, va_list av)
{
	if ((arg->size[0] == '\0' && arg->type != 'X')
		|| (ft_strcmp(arg->size, "h") == 0)
		|| (ft_strcmp(arg->size, "hh") == 0))
		nb = ft_itoa_base_ui(va_arg(av, unsigned int), 16, 0);
	else if (arg->type == 'X')
		nb = ft_itoa_base_lui(va_arg(av, unsigned long int), 16, 1);
	else if ((ft_strcmp(arg->size, "l") == 0))
		nb = ft_itoa_base_lui(va_arg(av, unsigned long), 16, 0);
	else if (ft_strcmp(arg->size, "ll") == 0)
		nb = ft_itoa_base_llui(va_arg(av, unsigned long long int), 16, 0);
	else if (ft_strcmp(arg->size, "j") == 0)
		nb = ft_itoa_base_uit(va_arg(av, uintmax_t), 16, 0);
	else if (ft_strcmp(arg->size, "z") == 0)
		nb = ft_itoa_base_it(va_arg(av, size_t), 16, 0);
	return (nb);
}
