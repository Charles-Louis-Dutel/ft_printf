/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:24 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/19 15:32:31 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_flags_number(char *s, va_list args)
{
	int	i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		return (0);
	else if (s[i] == 's')
			return (ft_fonctions_space(&s[0], args));
	else if (s[i] == 'c' || s[i] == 'u' || s[i] == 'p' || s[i] == 'x'
		|| s[i] == 'X'  || s[i] == 'd' || s[i] == 'i')
			return (ft_fonctions_space_2(&s[0], args));
	return (0);
}

static int	ft_check_flags_0_nbr(char *s, va_list args)
{
	int	i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.')
		return (0);
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X')
		return (ft_fonctions_point(&s[0], args));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_fonction_d_i_0(&s[0], args));
	return (0);
}

static int	ft_check_flags_0(char *s, va_list args)
{
	int	i;

	i = 0;
	while (s[i] == '0')
		i++;
	if (s[i] >= '1' && s[i] <= '9')
		return (ft_check_flags_0_nbr(&s[i], args));
	else if (s[i] == '-')
		return (ft_fonctions_moins(&s[i], args));
	else if (s[i] == '.')
		return (ft_fonctions_point(&s[i], args));
	else if (s[i] == '+')
		return (ft_fonctions_plus(&s[i], args));
	else if (s[i] == '#')
		return (ft_fonctions_diese(&s[i], args));
	else if (s[i] == ' ')
		return (ft_fonctions_space(&s[i], args));
	return (0);
}

int	ft_check_flags(char *s, va_list args)
{
	int	i;

	i = 0;
	if (s[0] >= '1' && s[0] <= '9')
		return (ft_check_flags_number(&s[i], args));
	if (s[0] == '.')
		return (ft_fonctions_point(&s[i], args));
	else if (s[0] == '0')
		return (ft_check_flags_0(&s[i], args));
	else if (s[0] == '-')
		return (ft_fonctions_moins(&s[i], args));
	else if (s[0] == '#')
		return (ft_fonctions_diese(&s[i], args));
	else if (s[0] == ' ')
		return (ft_fonctions_space(&s[i], args));
	else if (s[0] == '+')
		return (ft_fonctions_plus(&s[i], args));
	else if (s[0] != '0' || s[0] != '-' || s[0] != '.' || s[0] != '#'
		|| s[0] != ' ' || s[0] != '+')
		return (ft_put_args(s[0], args));
	return (0);
}
