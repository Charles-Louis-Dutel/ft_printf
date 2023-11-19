/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_moins2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:30:39 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/19 09:49:49 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_moins_hexa(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = ft_calcul_length_hexa(i);
	if (n > len)
		return (ft_convert_hexa(i) + ft_add_space(n - len));
	return (ft_convert_hexa(i));
}

int	ft_moins_hexamaj(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	len = ft_calcul_length_hexa(i);
	if (n > len)
		return (ft_convert_hexa_maj(i) + ft_add_space(n - len));
	return (ft_convert_hexa_maj(i));
}

int	ft_moins_adress(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned long long);
	len = ft_calcul_length_hexa(i) + 2;
	if (n > len)
		return (ft_convert_adress(i) + ft_add_space(n - len));
	return (ft_convert_adress(i));
}

int	ft_moins_c(va_list args, int n)
{
	char	c;

	c = va_arg(args, int);
	if (n > 1)
		return (ft_putchar(c) + ft_add_space(n - 1));
	return (ft_putchar(c));
}
