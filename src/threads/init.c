/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:51:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 21:26:43 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_threads( \
t_sim *sim, t_philo *philosophers, pthread_mutex_t *forks)
{
	t_routine_arg	*r_args;
	int				i;

	r_args = (t_routine_arg *) malloc(sim->num_of_philos * sizeof(t_routine_arg));
	if (r_args == NULL)
		return (FAIL);
	i = 0;
	while (i < sim->num_of_philos)
	{
		r_args[i].philosopher = &philosophers[i];
		r_args[i].forks = forks;
		r_args[i].fork_count = sim->num_of_philos;
		r_args[i].sim = sim;
		if (pthread_create(&philosophers[i].thread, NULL, &routine,
			(void *) &r_args[i]) != 0)
			return (FAIL);
		// TODO: rest of the func...
		++i;
	}
	set_int(&sim->sim_mutex, &sim->is_all_threads_ready, TRUE);
	
	// Observer
	free(r_args);
	r_args = (t_routine_arg *) malloc(1 * sizeof(t_routine_arg));
	if (r_args == NULL)
		return (FAIL);
	
	r_args->philosopher = philosophers;
	r_args->forks = forks;
	r_args->fork_count = sim->num_of_philos;
	r_args->sim = sim;
	if (pthread_create(&sim->observer_thread, NULL, &observe,
		(void *) r_args) != 0)
			return (FAIL);
	// TODO: free allocs?
	return (SUCCESS);
}
