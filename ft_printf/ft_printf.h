/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:41 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/11 20:52:38 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

# define STDOUT_FD 1

int	ft_printf(const char *fmt, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);

int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);

int	ft_putsize_base(size_t nbr, char *base);
int	ft_putunbr_hex(unsigned int n, int use_uppercase_notation);
int	ft_putunbr_ptr(size_t addr, int use_hex_prefix);

#endif