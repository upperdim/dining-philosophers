/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:47:20 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/06 18:07:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_sim *sim)
{
	sim->err_flag = 0;
}

void	parse_args(int argc, char *argv[], t_sim *sim)
{
	// TODO: atoi() / atol()
	sim->num_of_philos = atoi(argv[1]);
	sim->time_to_die_wo_eating = atoi(argv[2]);
	sim->time_to_eat = atoi(argv[3]);
	sim->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		sim->meal_limit = atoi(argv[5]);
	else
		sim->meal_limit = NO_MEAL_LIMIT;
	// TODO: Handle if max number of meals is 0
	// TODO: Handle if only 1 philo
}

int	validate_args(int argc, char *argv[])
{
	// TODO: str_is_numeric()
	// TODO: check for INT_MAX
	if (argc != 5 || argc != 6)
		return (EXIT_FAILURE);
	if (!str_is_int(argv[1]) || !str_is_numeric(argv[2]) 
		|| !str_is_numeric(argv[3]) || !str_is_numeric(argv[4])
		|| (argc == 6 && !str_is_numeric(argv[5])))
		return (FAIL);
	else
		return (SUCCESS);
}
