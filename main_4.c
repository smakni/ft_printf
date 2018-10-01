#include "ft_printf.h"

int main()
{
	printf("%s\n",setlocale(LC_ALL, ""));
	printf("(1)%C\n%d\n", 65, MB_CUR_MAX);
	return (0);
}
