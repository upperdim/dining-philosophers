/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/06 22:51:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
   Get the index of the first fork that philosophers prefer depending on their
   index. Odd numbers prefer index, even numbers prefer index + 1.
*/
int	get_first_fork_idx(t_philosopher *philosopher, int fork_count)
{
	if (philosopher->index % 2 == 1)
		return (philosopher->index);
	else
		return ((philosopher->index + 1) % fork_count);
}

/*
   Get the index of the first fork that philosophers prefer depending on their
   index. Odd numbers prefer index + 1, even numbers prefer index.
*/
int	get_second_fork_idx(t_philosopher *philosopher, int fork_count)
{
	if (philosopher->index % 2 == 1)
		return ((philosopher->index + 1) % fork_count);
	else
		return (philosopher->index);
}

void	routine(void *argument)
{
	t_routine_arg	*arg;

	arg = (t_routine_arg *)argument;
	wait_all_threads(arg->sim);
	while (!arg->philosopher->dead)
	{
		// TODO: have to check somewhere if this philosopher has to die.
		// In observer thread? otherwise where exactly in this thread?

		
		// Wait to eat
		pthread_mutex_lock(&arg->forks[get_first_fork_idx(arg->philosopher, arg->fork_count)]);
		pthread_mutex_lock(&arg->forks[get_second_fork_idx(arg->philosopher, arg->fork_count)]);
		// Eat
		arg->philosopher->num_times_ate++;
		if (gettimeofday(&arg->philosopher->last_eat_timestamp, NULL) == -1)
		{
			arg->philosopher->error_flag = 1;
			// todo: return?
		}
		pthread_mutex_unlock(&arg->forks[get_first_fork_idx(arg->philosopher, arg->fork_count)]);
		pthread_mutex_unlock(&arg->forks[get_second_fork_idx(arg->philosopher, arg->fork_count)]);
		
		
		// Think
		
		// Sleep
		struct timeval curr_time;
		if (gettimeofday(&curr_time, NULL) == -1)
		{
			arg->philosopher->error_flag = 1;
			// todo: return?
		}
		struct timeval wakeup_time;
		timev_add(&wakeup_time, curr_time, arg->sim->time_to_sleep);
		while (timev_cmp(curr_time, wakeup_time) == -1)
		{
			// keep sleeping
		}
		// wake up, proceed to eating state
	}
	// check if any locks are left 
	// 
}

int	init_threads( \
t_sim *sim, t_philosopher *philosophers, pthread_mutex_t *forks)
{
	t_routine_arg	*args;
	int				i;

	args = (t_routine_arg *) \
	safe_malloc(sim->num_of_philos * sizeof(t_routine_arg));
	i = 0;
	while (i < sim->num_of_philos)
	{
		args[i].philosopher = &philosophers[i];
		args[i].forks = forks;
		args[i].fork_count = sim->num_of_philos - 1;
		args[i].sim = sim;
		if (pthread_create(&philosophers[i].thread, NULL, &routine,
			(void *) &args[i]) != 0)
			return (FAIL);
		// TODO: rest of the func...
		++i;
	}
	set_int(&sim->sim_mutex, sim->is_all_threads_ready, TRUE);
	return (SUCCESS);
}

int	init_data(t_sim *sim, t_philosopher *philosophers, int *forks)
{
	int	i;

	philosophers = (t_philosopher *) \
	safe_malloc(sim->num_of_philos * sizeof(t_philosopher));
	forks = (pthread_mutex_t *) \
	safe_malloc(sim->num_of_philos * sizeof(pthread_mutex_t));
	safe_mutex_handle(&sim->sim_mutex, INIT);
	i = 0;
	while (i < sim->num_of_philos)
	{
		philosophers[i].index = i;
		philosophers[i].dead = FALSE;
		philosophers[i].error_flag = 0;
		// philosophers[i].fork_left = FORK_FREE;
		// philosophers[i].fork_right = FORK_FREE;
		philosophers[i].last_eat_timestamp = sim->start_timestamp;
		philosophers[i].num_times_ate = 0;
		safe_mutex_handle(&forks[i], INIT);
		++i;
	}
	if (gettimeofday(&(sim->start_timestamp), NULL) != 0)
		return (FAIL);
	return (SUCCESS);
}

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
	t_sim			sim;
	size_t			i;

	if (validate_args(argc, argv, &sim) == FAIL)
		return (EXIT_FAILURE);
	parse_args(argc, argv, &sim);
	if (init_data(&sim, philosophers, forks) == FAIL)
		return (EXIT_FAILURE);
	return (0);
}
