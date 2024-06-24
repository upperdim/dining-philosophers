/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:47:20 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 18:00:12 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Parse the integer in `src` string to `dest` int.
	Check if it has an underflow or overflow.
	Check if it is numeric in the first place.
	
	Return  0 upon success.
	Return -1 upon failure.
*/
static int	safe_atoi(int *dest, char *src)
{
	long	tmp;

	if (!str_is_numeric(src))
		return (FAIL);
	tmp = ft_atoi_l(src);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (FAIL);
	*dest = (int) tmp;
	return (SUCCESS);
}

static int	check_params(int argc, char *argv[], t_sim *sim)
{
	if (argc != 5 && argc != 6)
		return (printf("Invalid arg count\n"), FAIL);
	if (safe_atoi(&sim->num_of_philos, argv[1]) == FAIL
		|| sim->num_of_philos < 0)
		return (printf("Invalid number of philos\n"), FAIL);
	if (safe_atoi(&sim->time_to_die_wo_eating, argv[2]) == FAIL
		|| sim->time_to_die_wo_eating < 0)
		return (printf("Invalid time to die\n"), FAIL);
	if (safe_atoi(&sim->time_to_eat, argv[3]) == FAIL
		|| sim->time_to_eat < 0)
		return (printf("Invalid time to eat\n"), FAIL);
	if (safe_atoi(&sim->time_to_sleep, argv[4]) == FAIL
		|| sim->time_to_sleep < 0)
		return (printf("Invalid time to sleep\n"), FAIL);
	return (SUCCESS);
}

int	parse_args(int argc, char *argv[], t_sim *sim)
{
	if (check_params(argc, argv, sim) == FAIL)
		return (FAIL);
	if (argc == 6)
	{
		sim->meal_limit_exists = TRUE;
		if (safe_atoi(&sim->meal_limit, argv[5]) == FAIL
			|| sim->meal_limit <= 0)
		{
			printf("Invalid meal limit\n");
			return (FAIL);
		}
	}
	else
	{
		sim->meal_limit_exists = FALSE;
		sim->meal_limit = 0;
	}
	return (SUCCESS);
}
