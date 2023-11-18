/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:03:33 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/18 10:44:41 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_space(int i)
{
	int	result;

	i -= 1;
	if (i <= 0)
		return (0);
	result = 0;
	while (i != 0)
	{
		result += ft_putchar(' ');
		i--;
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

int	ft_fonctions_plus(char *s, va_list args)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while ((s[i] == '#') || (s[i] == ' ') || s[i] == '+')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
		n = ft_calcul_space(&s[i]);
	if (s[0 + ft_check_width(s)] == 'd' || s[0 + ft_check_width(s)] == 'i')
	{
		i = va_arg(args, int);
		n = ft_put_space(n - ft_length(i));
		return (ft_putnbr_plus(i) + n);
	}
	return (0);
}
