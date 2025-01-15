/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:30:38 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/22 17:30:38 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_unsigned_digits(unsigned int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb == 0)
		return (0);
	if (nb / 10 != 0)
		printed_chars += print_unsigned_digits(nb / 10);
	ft_putchar((nb % 10) + '0');
	printed_chars++;
	return (printed_chars);
}

int	printf_unsigned(unsigned int nb)
{
	int	printed_chars;

	printed_chars = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	printed_chars += print_unsigned_digits(nb);
	return (printed_chars);
}
