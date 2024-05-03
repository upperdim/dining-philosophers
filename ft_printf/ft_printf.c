/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:20:53 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/11 20:18:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
   Handle format specifiers and return number of characters printed onto screen.
   Return 0 (defined as SUCCESS) if no errors, else -1 (defined as FAILURE).
*/
static int	handle_specifiers(const char *fmt, va_list *valst)
{
	if (*fmt == 'c')
		return (ft_putchar((char) va_arg(*valst, int)));
	else if (*fmt == 's')
		return (ft_putstr(va_arg(*valst, char *)));
	else if (*fmt == 'p')
		return (ft_putunbr_ptr(va_arg(*valst, size_t), 1));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_putnbr(va_arg(*valst, int)));
	else if (*fmt == 'u')
		return (ft_putunbr(va_arg(*valst, unsigned int)));
	else if (*fmt == 'x')
		return (ft_putunbr_hex(va_arg(*valst, unsigned int), 0));
	else if (*fmt == 'X')
		return (ft_putunbr_hex(va_arg(*valst, unsigned int), 1));
	else if (*fmt == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	valist;
	int		print_count;
	int		ret;

	va_start(valist, fmt);
	print_count = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			ret = handle_specifiers(++fmt, &valist);
			if (ret < 0)
				return (-1);
			print_count += ret;
		}
		else
		{
			if (ft_putchar(*fmt) != 1)
				return (-1);
			++print_count;
		}
		++fmt;
	}
	va_end(valist);
	return (print_count);
}
