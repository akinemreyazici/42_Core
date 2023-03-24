/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyazici <akyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:32:34 by akyazici          #+#    #+#             */
/*   Updated: 2023/03/24 13:15:06 by akyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

int	ft_putstr(char *a)
{
	int	i;

	i = 0;
	if (!a)
		return (write(1, "(null)", 6));
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	return (i);
}

int	ft_point(unsigned long a, int check)
{
	int	i;

	i = 0;
	if (check == 1)
		i += write(1, "0x", 2);
	if (a >= 16)
		i += ft_point(a / 16, 0);
	write(1, &"0123456789abcdef"[a % 16], 1);
	return (i + 1);
}

int	ft_dec(int a)
{
	int	i;

	i = 0;
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		write(1, "-", 1);
		a *= -1;
		i++;
	}
	if (a >= 10)
		i += ft_dec(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (i + 1);
}

int	ft_udec(unsigned int a)
{
	unsigned int	i;

	i = 0;
	if (a >= 0 && a <= 9)
		return (write(1, &"0123456789"[a % 10], 1));
	if (a >= 10)
		i += ft_dec(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (i + 1);
}
