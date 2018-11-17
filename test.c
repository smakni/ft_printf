#include "ft_printf.h"

int main ()
{
	float	 x;
	long double q = 1444565444646.6465424242242;
	int		me;
	int		cp;

	x = 1424.525475;
//	ft_printf("%S\n", "salit");
//	printf("%S\n", "salit");
	/*y = ft_atoi(ft_itoa(x));
	printf("%d\n", y);
	y = ft_atoi(ft_itoa(x * 10));
	printf("%d\n", y);
	y = ft_atoi(ft_itoa(x * 100));
	printf("%d\n", y);
	y = ft_atoi(ft_itoa(x * 1000));
	printf("%d\n", y);*/
	//me = ft_printf("{%f}{%Lf}\n", 1444565444646.6465424242242, q);
	//cp = printf("{%f}{%Lf}\n", 1444565444646.6465424242242, q);
	ft_printf("me = %.10Lf\n", -14.42);
//	//ft_printf("me = %.10LF\n", 0);
	//printf("cp = %.10Lf\n", -14.42);
	//printf("cp = %.10LF\n", 0);
	//cp = printf("cp = %.10LF\n", q);
	// = ft_printf("me = %+020.d\n", 456);
	//me = printf("cp = %+020.d\n", 456);
	//printf("me = %d\ncp = %d\n", me, cp);
	//printf("MAX = %f\n", DBL_MAX);
	return (0);
}
	
