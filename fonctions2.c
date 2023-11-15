/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:25:30 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/15 07:01:29 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	if (n > 9)
	{
		i += ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
		i++;
	}
	return (i);
}

int	ft_convert_adress(unsigned long long n)
{
	char	*hexabase;
	int		i;

	i = 0;
	hexabase = "0123456789abcdef";
	ft_putchar('0');
	ft_putchar('x');
	i += 2;
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
