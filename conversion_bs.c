/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_bs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:59:36 by smakni            #+#    #+#             */
/*   Updated: 2018/10/20 18:22:00 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int check_error_C(unsigned int c)
{
	if ((c >= 55296 && c <= 57343) ||  c > 1114111)
		return (3);
	if (c <= 127)
		return (1);
	else if (c < 256 && MB_CUR_MAX == 1)
		return (1);
	else if (c <= 2047 && MB_CUR_MAX >=2)
		return (2);
	else if (c <= 65536 && MB_CUR_MAX >= 3)
		return (3);
   	 else if (c < 1114111 && MB_CUR_MAX >= 4)
		return (4);
	return (1);
}

static size_t ft_strwlen(const wchar_t *src)
{
	int		x;
	size_t 	i;

	i = 0;
	x = 0;
	while (src[i])
	{
		x += check_error_C(src[i]);
		i++;
	}
	return (x);
}

static size_t ft_strwlen2(const wchar_t *src)
{
	size_t 	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

/*
static void	*ft_memwcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	wchar_t	*dst_tmp;
	wchar_t	*src_tmp;

	dst_tmp = (wchar_t *)dst;
	src_tmp = (wchar_t *)src;
	i = 0;
	while (i < n)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst);
}


static char *ft_strwdup(const wchar_t *src)
{
	size_t 	i;
	size_t 	x;
	char	 *str;
	i = 0;
	x = ft_strwlen(src);
	if (!(str = malloc(sizeof(wchar_t) * x + 1)))
		return (0);
	while (i < x)
	{
		str[i] = src[i];
		i++;
	}
	str[i] ='\0';
	return (str);
}
*/
char	*conversion_bs(t_format *arg, va_list av)
{
	wchar_t *tmp;
	char 	*tmp_c;
	int 	x;
	size_t	len;
	size_t 	i;
	size_t 	j;
	char	*ret;

	i = 0;
	x = 0;
	j = 0;
	tmp = va_arg(av, wchar_t *);
	len = ft_strwlen2(tmp);
	j = ft_strwlen(tmp);
	//arg->res = ft_memalloc(sizeof(wchar_t) * j);
	ret = ft_memalloc(1);
	while (i <= len)
	{
		tmp_c = ft_memalloc(x = check_error_C(tmp[i]));
		tmp_c = ft_strdup(ft_putchar_printf(tmp[i], tmp_c, x));
	/*	ft_putstr("[x = ");
		ft_putnbr(x);
		ft_putstr(" / i = ");
		ft_putnbr(i);
		ft_putchar(']');
		printf("%s\n", tmp_c); */
		//j += x;
		ret = ft_strjoin(ret, tmp_c);
		//arg->res = ft_memjoin(arg->res, tmp_c, j, x);
	   	i++;
  	}
	ret[j] = '\0';
	arg->count = j;
	return (ret);
}
