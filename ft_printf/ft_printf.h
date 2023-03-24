/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyazici <akyazici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:32:08 by akyazici          #+#    #+#             */
/*   Updated: 2023/03/24 13:38:05 by akyazici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>

//utils
int	ft_putchar(char a);
int	ft_putstr(char *a);
int	ft_point(unsigned long a, int check);
int	ft_udec(unsigned int a);
int	ft_dec(int a);
int	ft_hex(unsigned int a, int check);

//main
int	ft_write(char str, va_list *a);
int	ft_checker(char str);
int	ft_printf(const char *str, ...);

#endif
