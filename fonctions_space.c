/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:03:42 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/19 15:40:55 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calcul_space(char *s)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

static int	ft_put_space(int nbr_space)
{
	int	result;

	result = 0;
	while (nbr_space != 0)
	{
		result += ft_putchar(' ');
		nbr_space--;
	}
	return (result);
}

int	ft_length(long i)
{
	int	result;

	if (i < 0)
		i *= -1;
	result = 0;
	while (i > 0)
	{
		result++;
		i /= 10;
	}
	return (result);
}

static int	ft_space_d_i(va_list args, int n)
{
	long	i;
	int		len;

	i = 0;
	len = 0;
	i = va_arg(args, int);
	if (i == 0 && n > 1)
		return (ft_put_space(n - 1) + ft_putnbr(0));
	if (i < 0)
	{
		i *= -1;
		if (n > ft_length(i) + 1)
			len = ft_put_space(n - (ft_length(i) + 1));
		len += ft_putchar('-');
	}
	else
	{
		if (n > ft_length(i))
			len = ft_put_space(n - ft_length(i));
		else if (n == 1)
			len = ft_put_space(n);
	}
	return (ft_putnbr(i) + len);
}

int	ft_fonctions_space(char *s, va_list args)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 1;
	while (s[i] == '#' || s[i] == ' ' || s[i] == '+' || s[i] == '0'
		|| s[i] == '-' || s[i] == '.')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_space_d_i(args, n));
	if (s[0 + ft_check_width(s)] == 's')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			n = 0;
		str = va_arg(args, char *);
		if (!str || n <= ft_strlen(str))
			n = 0;
		else
			n = ft_put_space(n - ft_strlen(str));
		return (ft_putstr(str) + n);
	}
	return (0);
}
