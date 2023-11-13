#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char *convert_to_hexa(unsigned c)
{
	char *hexa = "0123456789abcdef";
	char *convert;
	int i = 0;

	convert = malloc(sizeof(char) * 50);
	if (c / 16 > 0)
	{
		convert[i] = (hexa[c / 16]);
		//__builtin_printf("%c", convert[i]);
		i++;
		convert[i] = (hexa[c % 16]);
		__builtin_printf("%c", convert[i]);
		i++;
	}
	else
	{
		convert[i] = '0';
		i++;
		convert[i] = (hexa[c]);
		__builtin_printf("%c", convert[i]);
		i++;
	}
	//convert[i] = '\0';
	return (convert);
}

int main()
{
	//char *test;
	//char *test1;
	char *test2;

	//printf("%x\n", 45000);
	//test = convert_to_hexa(78);
	//test1 = convert_to_hexa('a');
	test2 = convert_to_hexa(45000);

	printf("%s", test2);

	return 0;
}
