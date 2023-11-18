/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_diese.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:45:18 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/18 11:10:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_space(int i)
{
	int	result;

	if (i <= 0)
		return (ft_putchar(' '));
	result = 0;
	while (i != 0)
	{
		result += ft_putchar(' ');
		i--;
	}
	return (result);
}

int	ft_calcul_length_hexa(unsigned long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 16)
	{
		i++;
	}
	if (n >= 16)
	{
		i += ft_calcul_length_hexa(n / 16);
		i += ft_calcul_length_hexa(n % 16);
	}
	return (i);
}

int	ft_calcul_length_0xhexa(unsigned long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	i += 2;
	if (n < 16)
	{
		i++;
	}
	if (n >= 16)
	{
		i += ft_calcul_length_hexa(n / 16);
		i += ft_calcul_length_hexa(n % 16);
	}
	return (i);
}

static int	ft_fonction_hexmaj(va_list args, int n)
{
	unsigned long long	i;

	i = 0;
	i = va_arg(args, unsigned);
	if (n > ft_calcul_length_0xhexa(i))
		n = ft_put_space(n - ft_calcul_length_0xhexa(i));
	else
		n = 0;
	return (ft_convert_0xmajhexa(i) + n);
}

int	ft_fonctions_diese(char *s, va_list args)
{
	unsigned long long	i;
	int					n;

	i = 0;
	n = 0;
	while ((s[i] == '#') || (s[i] == ' ') || s[i] == '+')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'x')
	{
		i = va_arg(args, unsigned);
		if (n > ft_calcul_length_0xhexa(i))
			n = ft_put_space(n - ft_calcul_length_0xhexa(i));
		else
			n = 0;
		return (ft_convert_0xhexa(i) + n);
	}
	if (s[0 + ft_check_width(s)] == 'X')
	{
		return (ft_fonction_hexmaj(args, n));
	}
	return (0);
}
