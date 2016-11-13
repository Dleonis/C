#include<stdio.h>
#include<stdarg.h>

void my_printf(char *ch, ...)
{
	int i = 0;
	va_list arg;
	puts(ch);
	va_start(arg, ch);
	puts(va_arg(arg, char*));
	for (i = 0; i < 4; i++)
	{
		putchar(va_arg(arg, int));
	}
	va_end(arg);
}
int main()
{
	my_printf("s ccc", "hello", 'b', 'i', 't','\n');
	return 0;
}
