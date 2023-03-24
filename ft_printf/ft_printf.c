/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyazici <akyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:31:19 by akyazici          #+#    #+#             */
/*   Updated: 2023/03/24 13:06:09 by akyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int a, int check)
{
	int	i;

	i = 0;
	if (a >= 16)
			i += ft_hex(a / 16, check);
	if (check == 0)
		write(1, &"0123456789abcdef"[a % 16], 1);
	else
		write(1, &"0123456789ABCDEF"[a % 16], 1);
	return (i + 1);
}

int	ft_write(char str, va_list *a)
{
	if (str == 'c')
		return (ft_putchar(va_arg(*a, int)));
	else if (str == 's')
		return (ft_putstr(va_arg(*a, char *)));
	else if (str == 'p')
		return (ft_point(va_arg(*a, unsigned long), 1));
	else if (str == 'd' || str == 'i')
		return (ft_dec(va_arg(*a, int)));
	else if (str == 'u')
		return (ft_udec(va_arg(*a, unsigned int)));
	else if (str == 'x' || str == 'X')
	{
		if (str == 'x')
			return (ft_hex(va_arg(*a, unsigned int), 0));
		else
			return (ft_hex(va_arg(*a, unsigned int), 1));
	}
	else if (str == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_checker(char str)
{
	if (str == 'c' || str == 's' || str == 'p'
		|| str == 'd' || str == 'i' || str == 'u'
		|| str == 'x' || str == 'X' || str == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	a;
	int		i;
	int		d;

	d = 0;
	i = -1;
	va_start(a, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_checker(str[i + 1]))
		{
			i++;
			d += ft_write(str[i], &a);
		}		
		else if (str[i] != '%')
		{
			d += write(1, &str[i], 1);
		}
	}
	va_end(a);
	return (d);
}
