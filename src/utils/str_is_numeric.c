/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_numeric.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:33:46 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 18:56:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Return whether string only consists of digits or not. */
int	str_is_numeric(char *s)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	if (s == NULL)
		return (1);
	if (len == 0)
		return (1);
	if (s[0] == '-' || s[0] == '+')
	{
		if (len == 1)
			return (0);
	}
	else if (!ft_isdigit(s[0]))
		return (0);
	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}
