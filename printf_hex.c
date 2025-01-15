/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:24:42 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/22 17:24:42 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*get_hex_digits(char base)
{
	if (base == 'x')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

static int	print_hex(unsigned int nb, const char *digits)
{
	unsigned int	tmp;
	char			buffer[100];
	int				i;
	int				res;

	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (nb != 0)
	{
		tmp = nb % 16;
		buffer[i] = digits[tmp];
		nb /= 16;
		i++;
	}
	res = i;
	while (i > 0)
	{
		i--;
		ft_putchar(buffer[i]);
	}
	return (res);
}

int	printf_hex(unsigned int nb, char base)
{
	const char	*digits;
	int			printed_chars;

	printed_chars = 0;
	digits = get_hex_digits(base);
	printed_chars += print_hex(nb, digits);
	return (printed_chars);
}
