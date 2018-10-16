#include "ft_printf.h"

int main()
{
	ft_printf("test(1)%d%d%d%dfin\n", 1, 2, 3, 4);
	ft_printf("test(2)%d%d%d%sfin\n", 1, 2, 3, "et");
	return (0);
}
