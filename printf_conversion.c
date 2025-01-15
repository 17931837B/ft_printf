/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:24:22 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/22 17:24:22 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_conversion(const char *format, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (*format == 'c')
		printed_chars += printf_char(va_arg(args, int));
	else if (*format == 's')
		printed_chars += printf_string(va_arg(args, char *));
	else if (*format == 'p')
		printed_chars += printf_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		printed_chars += printf_decimal(va_arg(args, int));
	else if (*format == 'u')
		printed_chars += printf_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		printed_chars += printf_hex(va_arg(args, unsigned int), *format);
	else if (*format == '%')
	{
		ft_putchar('%');
		printed_chars++;
	}
	return (printed_chars);
}
