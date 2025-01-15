/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:24:32 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/22 17:24:32 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	count_digits(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

int	printf_decimal(int nbr)
{
	int	printed_chars;

	printed_chars = 0;
	if (nbr == INT_MIN)
	{
		ft_putstr_fd("-2147483648", 1);
		printed_chars += 11;
		return (printed_chars);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		printed_chars++;
		nbr = -nbr;
	}
	ft_putnbr_fd(nbr, 1);
	printed_chars += count_digits(nbr);
	return (printed_chars);
}
