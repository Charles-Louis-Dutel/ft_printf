/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:03:42 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/18 11:41:26 by cdutel           ###   ########.fr       */
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

static int	ft_put_space(int nbr_space, int i)
{
	int	result;

	if (nbr_space <= 0 && i >= 0)
		return (ft_putchar(' '));
	result = 0;
	while (nbr_space != 0)
	{
		result += ft_putchar(' ');
		nbr_space--;
	}
	return (result);
}

static int	ft_length(int i)
{
	int	result;

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
	unsigned long long	i;

	i = 0;
	i = va_arg(args, int);
	if (i <= 0)
	{
		n = 1;
		n = ft_put_space(n - (ft_length(i)), i);
	}
	else
		n = ft_put_space(n - ft_length(i), i);
	return (ft_putnbr(i) + n);
}

int	ft_fonctions_space(char *s, va_list args)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	while ((s[i] == '#') || (s[i] == ' ') || s[i] == '+')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
		return (ft_space_d_i(args, n));
	if (s[0 + ft_check_width(s)] == 's')
	{
		str = va_arg(args, char *);
		if (n <= ft_strlen(str))
			n = 0;
		else
			n = ft_put_space(n - ft_strlen(str), i);
		return (ft_putstr(str) + n);
	}
	return (0);
}
