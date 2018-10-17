#include "ft_printf.h"

int main()
{
    setlocale(LC_ALL, "");
	ft_printf("--------------\n");
	(ft_printf("MYTEST : hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	ft_printf("\n--------------\n");
	(printf("CPTEST : hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	return (0);
}
