/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:03:08 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/15 09:28:05 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_put_args(char c, va_list args)
{
	if (c == 'c')
		return ft_putchar(va_arg(args, int));
	else if (c == 's')
		return ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		return ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		return ft_putnbr_unsigned(va_arg(args, unsigned));
	else if (c == 'x')
		return ft_convert_hexa(va_arg(args, unsigned));
	else if (c == 'X')
		return ft_convert_hexa_maj(va_arg(args, unsigned));
	else if (c == 'p')
		return ft_convert_adress(va_arg(args, unsigned long long));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i+1] == '%')
				ft_putchar('%');
			else
				len += ft_put_args(s[i+1], args);
			i += 2;
		}
		ft_putchar(s[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}

int main()
{
	int x;
	int y;
	int a;
	int b;
	int c;
	int d;
	a = 458;
	b = -458;
	c = 48849489;
	d = -1000;
	//x = ft_printf("test : %c , %s , %d , %u , %x , %X , %p , %p , %%\n", 'a', "bjr", 9745, -54, 589, 489995, (char *)311730411672, &a);
	//y = printf("test : %c , %s , %d , %u , %x , %X , %p , %p , %%\n", 'a', "bjr", 9745, -54, 589, 489995, (char *)311730411672, &a);
	//ft_convert_adress(311730411672);

	//x = ft_printf("test : %p , %p , %p , %p\n", (char *)458, "ewger", (char *)-5698, &a);
	//y = printf("test : %p , %p , %p , %p\n", (char *)458, "ewger", (char *)-5698, &a);

	/*x = ft_printf("test : %p , %p , %p , %p\n", &a, &b, &c, (char *)48849489);
	y = printf("test : %p , %p , %p , %p\n", &a, &b, &c, (char *)48849489);

	printf("%d\n", x);
	printf("%d\n", y);

	x = ft_printf("test : %p , %p , %p\n", (char *)458, (char *)-2147483647, (char *)48849489);
	y = printf("test : %p , %p , %p\n", (char *)458, (char *)-2147483647, (char *)48849489);

	printf("%d\n", x);
	printf("%d\n", y);*/

	//x = ft_printf("test : %p , %p , %p\n", (char *)-1000, "-1000", &d);
	//y = printf("test : %p , %p , %p\n", (char *)-1000, "-1000", &d);

	//x = ft_printf("test : %p\n", (void *)0);
	//y = printf("test : %p\n", (void *)0);

	x = ft_printf("test : %s\n", (char *)0);
	y = printf("test : %s\n", (char *)0);

	//x = 0;
	printf("%d\n", x);
	printf("%d\n", y);
	return 0;
}
