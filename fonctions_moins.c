/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_moins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:34:23 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/19 09:09:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_space(int len)
{
	int	i;

	i = 0;
	while (len != 0)
	{
		i += ft_putchar(' ');
		len--;
	}
	return (i);
}

int	ft_moins_d_i(va_list args, int n)
{
	long	i;
	int		len;

	i = va_arg(args, int);
	if (n - ft_length(i) <= 0)
		return (ft_putnbr(i));
	if (i < 0)
		len = n - (ft_length(i) + 1);
	else if (i == 0)
		len = n - 1;
	else
		len = n - ft_length(i);
	return (ft_putnbr(i) + ft_add_space(len));
}

int	ft_moins_u(va_list args, int n)
{
	unsigned long long	i;
	int					len;

	i = va_arg(args, unsigned);
	if (n - ft_length(i) <= 0)
		return (ft_putnbr_unsigned(i));
	else if (i == 0)
		len = n - 1;
	else
		len = n - ft_length(i);
	return (ft_putnbr_unsigned(i) + ft_add_space(len));
}

int	ft_moins_s(va_list args, int n)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	i = ft_strlen(str);
	if (n > i)
	{
		n -= i;
		return (ft_putstr(str) + ft_add_space(n));
	}
	return (ft_putstr(str));
}

int	ft_fonctions_moins(char *s, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s[i+1] >= '0' && s[i+1] <= '9')
		n = ft_calcul_space(&s[i+1]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_moins_d_i(args, n));
	if (s[0 + ft_check_width(s)] == 'u')
		return (ft_moins_u(args, n));
	if (s[0 + ft_check_width(s)] == 's')
		return (ft_moins_s(args, n));
	if (s[0 + ft_check_width(s)] == 'x')
		return (ft_moins_hexa(args, n));
	if (s[0 + ft_check_width(s)] == 'X')
		return (ft_moins_hexamaj(args, n));
	if (s[0 + ft_check_width(s)] == 'p')
		return (ft_moins_adress(args, n));
	if (s[0 + ft_check_width(s)] == 'c')
		return (ft_moins_c(args, n));
	return (0);
}
