/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:28:47 by egache            #+#    #+#             */
/*   Updated: 2024/11/28 12:14:15 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_printstr(char *str, int count)
{
	int	i;

	i = -1;
	while (str[++i])
		count += ft_putchar(str[i]);
	return (count);
}

int	ft_spectype(char c, va_list arg, int count)
{
	if (c == 'c' || c == '%')
		return (ft_putchar(c));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *), count));
	return (count);
	// if (c == 'p')
	// 	return (ft_printptr(va_arg(arg, void *), count));
	// if (c == 'd' || c == 'i')
	// 	return (ft_printint(va_arg(arg, int), count));
	// if (c == 'u')
	// 	return (ft_printuint(va_arg(arg, unsigned int), count));
	// if (c == 'x' || 'X')
	// 	return (ft_printhex(va_arg(arg, int), count))
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_spectype(str[++i], arg, count);
			i++;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(arg);
	return (count);
}

int	main(void)
{
	ft_printf("plop%splip", "ABCDEF");
	return (0);
}
