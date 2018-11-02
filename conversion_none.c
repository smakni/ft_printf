#include "ft_printf.h"

static void	conversion_none1(t_format *arg)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width)) == NULL)
		return ;
	if (ft_strchr(arg->option, '0') != 0)
		ft_memset(tmp, '0', arg->width);
	else
		ft_memset(tmp, ' ', arg->width);
	arg->res = ft_memjoin(arg->res, tmp, 1, arg->width);
	ft_strdel(&tmp);
}

static void	conversion_none2(t_format *arg)
{
	char *tmp;

	if ((tmp = ft_memalloc(arg->width + 1)) == NULL)
		return ;
	if (ft_strchr(arg->option, '0') != 0)
		ft_memset(tmp, '0', arg->width);
	else
		ft_memset(tmp, ' ', arg->width);
	arg->res = ft_memjoin(tmp, arg->res, arg->width - 1, 1);
}

void		conversion_none(t_format *arg)
{
	arg->res = ft_strsub(arg->str, arg->len - 1, 1); 
	if (arg->width > 1)
	{
		if (ft_strchr(arg->option, '-') != 0)
			conversion_none1(arg);
		else
			conversion_none2(arg);
		arg->count = arg->width;
	}
	else
		arg->count = 1;
}
