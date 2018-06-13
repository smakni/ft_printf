#include "cprintf.h" 

int affStr(va_list av) 
{ 
	putStr(va_arg(av, char *)); 
	return true; 
} 

int affCh(va_list av) 
{ 
	char c; 
	c = va_arg(av, int); 
	putCh(c); 
	return true; 
} 

int affInt(va_list av) 
{ 
	putInteger(va_arg(av, int)); 
	return true; 
}
