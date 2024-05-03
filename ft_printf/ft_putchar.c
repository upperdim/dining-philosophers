/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:45:16 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/11 20:53:02 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
   Write character `c` into standard output
   and return number of characters printed on the screen.

   Return -1 if write fails or upon any error.
*/
int	ft_putchar(char c)
{
	ssize_t	ret;

	ret = write(STDOUT_FD, &c, 1);
	if (ret != 1)
		return (-1);
	return (ret);
}
