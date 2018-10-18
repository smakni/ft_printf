#include "ft_printf.h"

int main()
{
    setlocale(LC_ALL, "");
	ft_printf("--------------\n");
	ft_putnbr(ft_printf("MYTEST : hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0));
	ft_printf("\n--------------\n");
	ft_putnbr(printf("CPTEST : hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0));

	return (0);
}
