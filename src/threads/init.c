/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:51:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 16:35:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_observer(t_sim *sim, t_philo *philos, pthread_mutex_t *forks)
{
	sim->observer_r_arg = (t_routine_arg *) malloc(1 * sizeof(t_routine_arg));
	if (sim->observer_r_arg == NULL)
		return (FAIL);
	sim->observer_r_arg->philo = philos;
	sim->observer_r_arg->forks = forks;
	sim->observer_r_arg->fork_count = sim->num_of_philos;
	sim->observer_r_arg->sim = sim;
	if (pthread_create(&sim->observer_thread, NULL, &observe, \
	(void *) sim->observer_r_arg) != 0)
		return (FAIL);
	return (SUCCESS);
}

static int	init_philos(t_sim *sim, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	sim->philo_r_args_arr = (t_routine_arg *) \
	malloc(sim->num_of_philos * sizeof(t_routine_arg));
	if (sim->philo_r_args_arr == NULL)
		return (FAIL);
	i = 0;
	while (i < sim->num_of_philos)
	{
		sim->philo_r_args_arr[i].philo = &philos[i];
		sim->philo_r_args_arr[i].forks = forks;
		sim->philo_r_args_arr[i].fork_count = sim->num_of_philos;
		sim->philo_r_args_arr[i].sim = sim;
		if (pthread_create(&philos[i].thread, NULL, &routine, \
		(void *) &sim->philo_r_args_arr[i]) != 0)
			return (FAIL);
		++i;
	}
	return (SUCCESS);
}

int	init_threads(t_sim *sim, t_philo *philosophers, pthread_mutex_t *forks)
{
	if (init_philos(sim, philosophers, forks) == FAIL
		|| init_observer(sim, philosophers, forks) == FAIL)
		return (FAIL);
	set_int(&sim->sim_mutex, &sim->is_all_threads_ready, TRUE);
	return (SUCCESS);
}
