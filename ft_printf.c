/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:22:42 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/13 18:57:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_putnbr_in_tab(char *tab, long n, int i)
{
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
		i++;
	}
	if (n <= 9)
	{
		tab[i] = n + '0';
		i++;
	}
	if (n > 9)
	{
		i--;
		ft_putnbr_in_tab(tab, (n / 10), i);
		i++;
		ft_putnbr_in_tab(tab, (n % 10), i);
	}
	return (tab);
}

char	*ft_putnbr_in_tab_u(char *tab, unsigned n, int i)
{
	if (n <= 9)
	{
		tab[i] = n + '0';
		i++;
	}
	if (n > 9)
	{
		i--;
		ft_putnbr_in_tab(tab, (n / 10), i);
		i++;
		ft_putnbr_in_tab(tab, (n % 10), i);
	}
	return (tab);
}

int	ft_size_tab(double n)
{
	int		a;
	int		i;

	i = 0;
	if (n == 0)
		i = 1;
	else
	{
		a = n;
		while (a != 0)
		{
			a /= 10;
			i++;
		}
	}
	return (i);
}

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
		i++;
		convert[i] = (hexa[c % 16]);
		i++;
	}
	else
	{
		convert[i] = '0';
		i++;
		convert[i] = (hexa[c]);
		i++;
	}
	convert[i] = '\0';
	return (convert);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);

	char str[1000];

	char *test;
	int	i = 0;
	int j = 0;
	int x = 0;
	unsigned u = 0;

	while (s[i])
	{
		if (s[i] == 37)
		{
			i++;
			if (s[i] == 'c')
			{
				i++;
				x = va_arg(args, int);
				str[j] = x;
				j++;
			}
			else if (s[i] == 'd')
			{
				i++;
				x = va_arg(args, int);
				ft_putnbr_in_tab(&str[j], x, (ft_size_tab(x)-1));
				j += ft_size_tab(x);
				if (x < 0)
					j++;
			}
			else if (s[i] == 's')
			{
				i++;
				test = va_arg(args, char*);
				x = 0;
				while (test[x])
				{
					str[j] = test[x];
					j++;
					x++;
				}
			}
			else if (s[i] == 'u')
			{
				i++;
				x = va_arg(args, int);
				if (x >= -2147483647 && x <= 2147483647)
					u = x;
				ft_putnbr_in_tab_u(&str[j], u, (ft_size_tab(u)-1));
				j += ft_size_tab(u);
			}
			/*else if (s[i] == 'x')
			{

			}*/
		}
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	j = 0;
	while (str[j])
	{
		write(1, &str[j], 1);
		j++;
	}
	va_end(args);
	return (strlen(str));
}

int main()
{
	int x;
	char *test;
	char *test1;
	char *test2;


	x = ft_printf("%d bonjour %c   %s  %d bjr \n%u \n\n", -97, 'z', "je sais pas si ca marche vraiment comme ca", 2147483647, -2147483);
	printf("%d bonjour %c   %s  %d bjr \n%u \n\n", -97, 'z', "je sais pas si ca marche vraiment comme ca", 2147483647, -2147483);


	printf("%x  %x  %x\n", 78, 'a', 45000);
	test = convert_to_hexa(78);
	test1 = convert_to_hexa('a');
	test2 = convert_to_hexa(45000);

	printf("%s  %s  %s", test, test1, test2);

	return 0;
}
