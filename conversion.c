#include "ft_printf.h"

void	conversion_s(t_format *arg, va_list av)
{
	char 	*tmp;
	int		len;
	int		i;

	if (arg->width == 0 && arg->precision == 0)
		return (ft_putstr(va_arg(av, char *)));
	i = 0;
	tmp = ft_strdup(va_arg(av, char *));
	len = ft_strlen(tmp);
	if (arg->precision < len)
	{
		while(tmp[i] && i < arg->precision)
			i++;
		tmp = ft_strsub_free(tmp, 0, i);
		len = ft_strlen(tmp);
		i = 0;
	}
	if (arg->width > len)
	{
		arg->res = ft_memalloc(arg->width + 1);
		if (ft_strchr(arg->option, '0') != 0 && ft_strchr(arg->option, '-') == 0)
			ft_memset(arg->res, '0', arg->width);
		else
			ft_memset(arg->res, ' ', arg->width);
		if (ft_strchr(arg->option, '-') != 0)
			while (tmp[i])
			{
				arg->res[i] = tmp[i];
				i++;
			}
		else
			while (tmp[i])
			{
				arg->res[arg->width - len + i] = tmp[i];
				i++;
			}
	}
	else
		arg->res = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_putstr(arg->res);
}

void	conversion_c(t_format *arg, va_list av)
{
	int				i;

	i = 0;
	if (arg->width > 1) 
	{
		if (!(arg->res = ft_memalloc(arg->width)))
			return ;
		ft_memset(arg->res, ' ', arg->width - 1);
		ft_putstr(arg->res);
		ft_strdel(&(arg)->res);
	}
	ft_putchar(va_arg(av, int));
}
