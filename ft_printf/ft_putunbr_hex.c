/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:48:27 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/05 16:48:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
   Write number `n` into standard output in hexadecimal base 
   and return the number of characters printed.
   Return -1 if ft_putsize_base fails or upon any error.

   Uppercase hexadecimal notation will be used if `use_uppercase_notation`
   flag is true.
*/
int	ft_putunbr_hex(unsigned int n, int use_uppercase_notation)
{
	if (use_uppercase_notation)
		return (ft_putsize_base((size_t) n, "0123456789ABCDEF"));
	else
		return (ft_putsize_base((size_t) n, "0123456789abcdef"));
}
