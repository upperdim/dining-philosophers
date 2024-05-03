/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:44:02 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/11 20:52:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
   Longest integer we can receive is 4294967295 with length 10.
   We need 11 characters including the null-terminator.
*/
#define U_BUFF_SIZE 11

static int	count_digits_unsigned(unsigned int nb)
{
	int	digit_count;

	if (nb == 0)
		return (1);
	digit_count = 0;
	while (nb != 0)
	{
		nb /= 10;
		++digit_count;
	}
	return (digit_count);
}

/*
   Print an unsigned number to the standard out 
   and return number of characters printed.
   Return -1 if write fails or upon any error.
*/
int	ft_putunbr(unsigned int nb)
{
	char	buff[U_BUFF_SIZE];
	int		buff_idx;
	size_t	num_len;
	ssize_t	ret;

	buff[0] = '0';
	buff_idx = count_digits_unsigned(nb);
	buff[buff_idx--] = '\0';
	while (nb > 0)
	{
		buff[buff_idx] = '0' + (nb % 10);
		nb /= 10;
		--buff_idx;
	}
	num_len = ft_strlen(buff);
	ret = write(STDOUT_FD, buff, num_len);
	if (ret != (ssize_t) num_len)
		return (-1);
	return (ret);
}
