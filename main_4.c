#include "ft_printf.h"

int main()
{
    setlocale(LC_ALL, "");
	ft_printf("test(1)%d%d%d%dfin\n", 1, 2, 3, 4);
	ft_printf("test(2)%d%d%d%sfin\n", 1, 2, 3, "et");
	ft_printf("test(3)%%%%%d%d%d%sfin\n", 1, 2, 3, "et");
	ft_printf("test(4)%c", 24855);
	return (0);
}
