/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobaba <tobaba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:01:15 by tobaba            #+#    #+#             */
/*   Updated: 2024/04/28 11:01:15 by tobaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(char c);
int		printf_char(char c);
int		printf_conversion(const char *format, va_list args);
int		ft_printf(const char *format, ...);
int		printf_decimal(int nbr);
int		printf_hex(unsigned int nb, char base);
int		printf_pointer(void *ptr);
int		printf_string(const char *str);
int		printf_unsigned(unsigned int nb);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);

#endif