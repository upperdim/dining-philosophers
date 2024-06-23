/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:24:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 16:24:12 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	s_isspace3(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

/* Parse aa long from a string and return it. */
long	ft_atoi_l(const char *str)
{
	int				sign;
	long			result;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (s_isspace3(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0') % 10;
		i++;
	}
	return (result * sign);
}
