#include <stdlib.h> 

void putCh(char c) 
{ 
	write(1, &c, 1); 
} 

void putStr(const char *str) 
{
	size_t i = 0; 
	while (str[i]) 
	putCh(str[i++]); 
} 

void putInteger(int nb) 
{ 
	if (nb < 0) 
	{ 
		putCh('-'); 
		nb = nb * (-1); 
	} 
	if (nb >= 10) 
	{
		putInteger(nb / 10); 
		putInteger(nb % 10); 
	} 
	else putCh('0' + nb); 
}
