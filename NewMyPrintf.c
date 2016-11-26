#include<stdio.h>
#include<stdarg.h>

void IntPrintf(int nums)
{
	if(nums > 9)
	{
		IntPrintf(nums / 10);
	}
	putchar((nums % 10) + '0');
}

void MyPrintf(const char *src, ...)
{
	va_list va;
	va_start(va, src);
	while(*src)
	{
		if(*src == '%')
		{
			char c = *++src;
			switch(c)
			{
				case 'd':
					IntPrintf(va_arg(va, int));
					break;
				case 'c':
					putchar(va_arg(va, char));
					break;
				case 's':
					puts(va_arg(va, char*));
					break;
				default:
					putchar('%');
					putchar(c);
					break;
			}
		}
		else
		{
			putchar(*src);
		}
		src++;
	}

}

int main()
{
	MyPrintf("%dhehe %chaha %shoho", 123, 'A', "hello bit");
	return 0;
}
