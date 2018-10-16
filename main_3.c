#include "ft_printf.h"

int main()
{
	printf("%s\n",setlocale(LC_ALL, ""));
	printf("(1)%C\n%d\n", 65, MB_CUR_MAX);
	printf("(2)%C\n%d\n", 233, MB_CUR_MAX);
	printf("(3)%C\n%d\n", 63743, MB_CUR_MAX);
	printf("(4)%C\n%d\n", 119070, MB_CUR_MAX);
	printf("(5)salut%C\n%d\n", 0x11ffff, MB_CUR_MAX);
	return (0);
}
