/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:05:07 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/11 20:52:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
   Longest integer we can receive is -2147483647 with length 11.
   We need 12 characters including the null-terminator.
*/
#define BUFF_SIZE 12

static int	count_digits(int nb)
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
   Write `buff` to the stdout and return number of characters printed.
   Return -1 upon errors.
   
   Helper function for ft_putnbr purely because of Norm coding standards' 
   25 lines limit for functions. I will sacrifica some elegance and readability
   for performance.
*/
static int	ft_putnbr_helper(char *buff)
{
	int	ret;
	int	buff_len;

	buff_len = ft_strlen(buff);
	ret = write(STDOUT_FD, buff, buff_len);
	if (ret != (ssize_t) buff_len)
		return (-1);
	return (ret);
}

/*
   Print a number to the standard out and return number of characters printed.
   Return -1 if write fails or upon any error.
*/
int	ft_putnbr(int nb)
{
	char	buff[BUFF_SIZE];
	int		buff_idx;

	if (nb >= 0)
	{
		buff_idx = count_digits(nb);
		buff[0] = '0';
		nb = -nb;
	}
	else
	{
		buff_idx = count_digits(nb) + 1;
		buff[0] = '-';
	}
	buff[buff_idx--] = '\0';
	while (nb < 0)
	{
		buff[buff_idx--] = '0' + -(nb % 10);
		nb /= 10;
	}
	return (ft_putnbr_helper(buff));
}
