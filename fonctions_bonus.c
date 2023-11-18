/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:00:09 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/18 11:11:16 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_convert_0xhexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	hexabase = "0123456789abcdef";
	i += ft_putchar('0');
	i += ft_putchar('x');
	if (n < 16)
	{
		i += ft_putchar(hexabase[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa(n / 16);
		i += ft_convert_hexa(n % 16);
	}
	return (i);
}

int	ft_convert_0xmajhexa(unsigned long long n)
{
	char	*hexabase;
	int		i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	hexabase = "0123456789ABCDEF";
	i += ft_putchar('0');
	i += ft_putchar('X');
	if (n < 16)
	{
		i += ft_putchar(hexabase[n]);
	}
	if (n >= 16)
	{
		i += ft_convert_hexa_maj(n / 16);
		i += ft_convert_hexa_maj(n % 16);
	}
	return (i);
}

int	ft_putnbr_plus(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	else if (n >= 0)
		i += ft_putchar('+');
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
