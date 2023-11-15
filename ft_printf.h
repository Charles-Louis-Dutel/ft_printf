/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:26:26 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/15 02:39:21 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_convert_hexa(unsigned int n);
int	ft_convert_hexa_maj(unsigned int n);
int	ft_convert_adress(size_t n);

#endif
