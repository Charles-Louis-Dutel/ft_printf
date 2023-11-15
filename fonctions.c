/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:29:15 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/15 09:29:02 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int i;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		ft_putnbr(n % 10);
		i++;
	}
	return (i);
}

int	ft_convert_hexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	i = 0;
	hexabase = "0123456789abcdef";
	if (n < 16)
	{
		i += ft_putchar(hexabase[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa(n / 16);
		ft_convert_hexa(n % 16);
		i++;
	}
	return (i);
}

int	ft_convert_hexa_maj(unsigned int n)
{
	char	*hexa_maj;
	int		i;

	i = 0;
	hexa_maj = "0123456789ABCDEF";
	if (n < 16)
	{
		i += ft_putchar(hexa_maj[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_maj(n / 16);
		ft_convert_hexa_maj(n % 16);
		i++;
	}
	return (i);
}

/*int main()
{
	//ft_convert_hexa('b');
	printf("\n%x\n", 4202539);
}*/
