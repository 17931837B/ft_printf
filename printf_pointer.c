/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:26:27 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/22 17:26:27 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_zero(void)
{
	write(1, "0", 1);
	return (1);
}

static int	print_pointer_value(unsigned long long value, const char *hex_chars)
{
	int		printed_chars;
	char	buffer[64];
	int		index;
	int		digit;
	int		i;

	printed_chars = 0;
	index = 0;
	if (value == 0)
		return (print_zero());
	while (value)
	{
		digit = value % 16;
		buffer[index++] = hex_chars[digit];
		value /= 16;
	}
	i = index - 1;
	while (i >= 0)
	{
		printed_chars += write(1, &buffer[i], 1);
		i--;
	}
	return (printed_chars);
}

int	printf_pointer(void *ptr)
{
	int					printed_chars;
	unsigned long long	value;
	char				*hex_chars;

	printed_chars = 0;
	value = (unsigned long long)ptr;
	hex_chars = "0123456789abcdef";
	printed_chars += write(1, "0x", 2);
	printed_chars += print_pointer_value(value, hex_chars);
	return (printed_chars);
}
