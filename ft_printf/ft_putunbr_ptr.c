/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:47:54 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/05 16:48:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
   Write number `n` into standard output in hexadecimal base 
   and return the number of characters printed.
   Return -1 if ft_putstr fails or upon any error.

   Prefix "0x" to the number if `use_hex_prefix` is true.
*/
int	ft_putunbr_ptr(size_t addr, int use_hex_prefix)
{
	int	printed_count;
	int	ret;

	printed_count = 0;
	if (use_hex_prefix)
	{
		ret = ft_putstr("0x");
		if (ret != 2)
			return (-1);
		printed_count += ret;
	}
	ret = ft_putsize_base(addr, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	printed_count += ret;
	return (printed_count);
}
