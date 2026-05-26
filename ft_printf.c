/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dandrush <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:39:42 by dandrush          #+#    #+#             */
/*   Updated: 2026/05/26 15:44:46 by dandrush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_format(va_list args, char format)
{
	char	*str;
	int		nbr;

	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	if (format == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (ft_putstr_fd(str, 1), ft_strlen(str));
	}
	if (format == 'p')
		return (ft_putptr(va_arg(args, uintptr_t)));
	if (format == 'd' || format == 'i')
		return (nbr = va_arg(args, int), ft_putnbr_fd(nbr, 1), ft_nbrlen(nbr));
	if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format));
	if (format == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_len += ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}

/*
#include <stdio.h>
#include <limits.h>

void	test_header(const char *title)
{
	printf("\n=========================================\n");
	printf("        ТЕСТИРОВАНИЕ: %s\n", title);
	printf("=========================================\n");
}

int	main(void)
{
	int		res_orig;
	int		res_ft;
	void	*ptr;

	test_header("СИМВОЛЫ (%c)");
	res_orig = printf("ORIG: Сим.: [%c], Про: [%c], Не.: [%c]\n", 'A', ' ', 1);
	res_ft = ft_printf("FT: Сим.: [%c], Проб: [%c], Не.: [%c]\n", 'A', ' ', 1);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	test_header("СТРОКИ (%s)");
	res_orig = printf("ORIG: Стр: [%s], Пуст: [%s]\n", "Привет, 42!", "");
	res_ft   = ft_printf("FT: Стр: [%s], Пуст: [%s]\n", "Привет, 42!", "");
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	res_orig = printf("ORIG: NULL строка: [%s]\n", (char *)NULL);
	res_ft   = ft_printf("FT: NULL строка: [%s]\n", (char *)NULL);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	test_header("ЗНАКОВЫЕ ЦЕЛЫЕ (%d / %i)");
	res_orig = printf("ORIG: Ноль: %d, Полож: %i, Отр: %d\n", 0, 4242, -12345);
	res_ft = ft_printf("FT: Ноль: %d, Полож: %i, Отр: %d\n", 0, 4242, -12345);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	res_orig = printf("ORIG: INT_MAX: %d, INT_MIN: %i\n", INT_MAX, INT_MIN);
	res_ft = ft_printf("FT: INT_MAX: %d, INT_MIN: %i\n", INT_MAX, INT_MIN);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	test_header("БЕЗЗНАКОВЫЕ ЦЕЛЫЕ (%u)");
	res_orig = printf("OR: 0: %u, Мак: %u, Из отр: %u\n", 0, UINT_MAX, -1);
	res_ft = ft_printf("FT: 0: %u, Мак: %u, Из отриц: %u\n", 0, UINT_MAX, -1);
	printf("Длина -> Or: %d | Ft: %d\n", res_orig, res_ft);

	test_header("ШЕСТНАДЦАТЕРИЧНЫЕ (%x / %X)");
	res_orig = printf("OR: Н:%x, В:%X, 0:%x, М:%X\n", 255, 255, 0, UINT_MAX);
	res_ft = ft_printf("FT: Н:%x, В:%X, 0:%x, М:%X\n", 255, 255, 0, UINT_MAX);
	printf("Длина -> Or: %d | Ft: %d\n", res_orig, res_ft);

	test_header("УКАЗАТЕЛИ (%p)");
	ptr = &res_orig;
	res_orig = printf("ORIG: Вал.ptr: %p, Адр main: %p\n", ptr, (void *)&main);
	res_ft = ft_printf("FT: Вал.ptr: %p, Адр main: %p\n", ptr, (void *)&main);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	res_orig = printf("ORIG: NULL указатель: %p\n", (void *)NULL);
	res_ft = ft_printf("FT: NULL указатель: %p\n", (void *)NULL);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	test_header("СИМВОЛ ПРОЦЕНТА (%%)");
	res_orig = printf("ORIG: Одиноч: %%, Тройной: %%%%%%\n");
	res_ft   = ft_printf("FT: Одиноч: %%, Тройной: %%%%%%\n");
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	test_header("СЛОЖНЫЙ МИКС ФЛАГОВ");
	res_orig = printf("OR: П %s нб %d о из %X%%  Ptr: %p\n", "D", 42, 10, ptr);
	res_ft = ft_printf("FT: П %s нб %d о из %X%%  Ptr: %p\n", "D", 42, 10, ptr);
	printf("Длина -> Orig: %d | Ft: %d\n", res_orig, res_ft);

	printf("\n=========================================\n");
	return (0);
}
*/
