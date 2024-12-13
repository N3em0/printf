/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:28:47 by egache            #+#    #+#             */
/*   Updated: 2024/12/13 15:30:42 by egache           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_spectype(char c, va_list arg, int count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 's')
		return (ft_printstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_printint(va_arg(arg, int)));
	if (c == 'u')
		return (ft_printuint(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(arg, unsigned int), c));
	return (count);
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
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	ptr;
// 	int original, custom;
// 	original = printf("Original: Hello %u %d %s %i a%p b%p c%p isthisNULL%s!\n", 124, 88851556, "cc", 8, (void *)&ptr, &ptr, (void *)NULL, NULL);
// 	custom = ft_printf("Original: Hello %u %d %s %i a%p b%p c%p isthisNULL%s!\n", 124, 88851556, "cc", 8, (void *)&ptr, &ptr, (void *)NULL, NULL);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// }
// #include <limits.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	num;

// 	int original, custom;
// 	// Basic string tests
// 	printf("\n=== String Tests ===\n");
// 	original = printf("Original: Hello %s!\n", "World");
// 	custom = ft_printf("Custom  : Hello %s!\n", "World");
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Integer tests
// 	printf("\n=== Integer Tests %%d ===\n");
// 	original = printf("Original: %d, %d\n", 42, -42);
// 	custom = ft_printf("Custom  : %d, %d\n", 42, -42);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Integer tests 2
// 	printf("\n=== Integer Tests %%i ===\n");
// 	original = printf("Original: %i, %i\n", 42, -42);
// 	custom = ft_printf("Custom  : %i, %i\n", 42, -42);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Unsigned tests
// 	printf("\n=== Unsigned Tests ===\n");
// 	original = printf("Original: %u\n", UINT_MAX);
// 	custom = ft_printf("Custom  : %u\n", UINT_MAX);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Hex tests
// 	printf("\n=== Hex Tests ===\n");
// 	original = printf("Original: %x %X\n", 255, 255);
// 	custom = ft_printf("Custom  : %x %X\n", 255, 255);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Pointer tests
// 	num = 42;
// 	printf("\n=== Pointer Tests ===\n");
// 	original = printf("Original: %p\n", (void *)&num);
// 	custom = ft_printf("Custom  : %p\n", (void *)&num);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Char tests
// 	printf("\n=== Char Tests ===\n");
// 	original = printf("Original: %c%c%c\n", 'a', '\t', 'b');
// 	custom = ft_printf("Custom  : %c%c%c\n", 'a', '\t', 'b');
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Edge case: null string
// 	printf("\n=== Edge Case: NULL string ===\n");
// 	original = printf("Original: %s\n", (char *)NULL);
// 	custom = ft_printf("Custom  : %s\n", (char *)NULL);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Edge case: null pointer
// 	printf("\n=== Edge Case: NULL pointer ===\n");
// 	original = printf("Original: %p\n", (void *)NULL);
// 	custom = ft_printf("Custom  : %p\n", (void *)NULL);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Edge case: percent sign
// 	printf("\n=== Edge Cases: percent sign ===\n");
// 	original = printf("Original: %%\n");
// 	custom = ft_printf("Custom  : %%\n");
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	// Edge case: INT_MIN
// 	printf("\n=== Edge Cases: INT_MIN ===\n");
// 	original = printf("Original: %d %s\n", INT_MIN, (char *)NULL);
// 	custom = ft_printf("Custom  : %d %s\n", INT_MIN, NULL);
// 	printf("Length check: original=%d, custom=%d\n", original, custom);
// 	return (0);
// }
