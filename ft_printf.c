/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:28:47 by egache            #+#    #+#             */
/*   Updated: 2024/11/28 00:23:04 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (str[i++] == '%')
		{
			count += ft_spectype(str[i], arg, count);
		}
		else
			i++;
			count += ft_putchar(str[i]);
	}
	va_end(arg);
	return (count);
}

int	ft_spectype(char c, va_list arg, int i)
{
	if (c == 'c' || c == '%')
		return (ft_putchar(c));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *), i));
	if (c == 'p')
		return (ft_printptr(va_arg(arg, void *), i));
	if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(arg, int), i));
	if (c == 'u')
		return (ft_printuint(va_arg(arg, unsigned int), i));
	if (c == 'x' || 'X')
		return (ft_printhex(va_arg(arg, int), i))



}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


printf("%s %d mabite", "monboule", 48, 49)
