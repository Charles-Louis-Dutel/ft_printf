
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(int a, ...)
{
	va_list	args;

	va_start(args, a);

	int s = a;
	printf("%d\n", s);
	int i;
	int x = va_arg(args, int);
	printf("%d\n", x);

	while (x != 0)
	{
		s += x;
		x = va_arg(args, int);
		printf("%d\n", x);
	}
	va_end(args);
	return (s);
}

int main()
{
	printf("%d\n", ft_printf(5, 2, 4, 5, 10, 0));
	return (0);
}
