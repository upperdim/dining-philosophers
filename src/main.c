/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:39:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 19:38:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_sim *sim, t_philo *philosophers, pthread_mutex_t *forks)
{
	int	i;

	sim->err_flag = 0;
	sim->is_all_threads_ready = FALSE;
	sim->finished = FALSE;
	pthread_mutex_init(&sim->sim_mutex, NULL);
	pthread_mutex_init(&sim->write_mutex, NULL);
	if (gettimeofday(&(sim->start_timestamp), NULL) != 0)
		return (FAIL);
	i = 0;
	while (i < sim->num_of_philos)
	{
		philosophers[i].index = i;
		philosophers[i].dead = FALSE;
		philosophers[i].error_flag = 0;
		philosophers[i].state = STATE_NA;
		philosophers[i].last_eat_timestamp = sim->start_timestamp;
		philosophers[i].num_times_ate = 0;
		pthread_mutex_init(&philosophers[i].mutex, NULL);
		pthread_mutex_init(&forks[i], NULL);
		++i;
	}
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	t_philo	*philosophers;
	t_sim			sim;

	if (parse_args(argc, argv, &sim) == FAIL)
			return (EXIT_FAILURE);
	if (sim.num_of_philos == 1)
		return (0);

	philosophers = (t_philo *) malloc(sim.num_of_philos * sizeof(t_philo));
	forks = (pthread_mutex_t *) \
	malloc(sim.num_of_philos * sizeof(pthread_mutex_t));
	if (philosophers == NULL || forks == NULL)
		return (FAIL);
	
	if (init_data(&sim, philosophers, forks) == FAIL)
		return (EXIT_FAILURE);
	init_threads(&sim, philosophers, forks);
	join_threads(&sim, philosophers);
 
	// TODO: free allocated data (philosophers, forks, etc.)
	return (0);
}
