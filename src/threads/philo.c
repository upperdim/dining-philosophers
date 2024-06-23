/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 19:38:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
   Get the index of the first fork that philosophers prefer depending on their
   index. Odd numbers prefer index, even numbers prefer index + 1.
*/
static int	get_first_fork_idx(t_philo *philosopher, int fork_count)
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
static int	get_second_fork_idx(t_philo *philosopher, int fork_count)
{
	if (philosopher->index % 2 == 1)
		return ((philosopher->index + 1) % fork_count);
	else
		return (philosopher->index);
}

void	*routine(void *argument)
{
	t_routine_arg	*arg;

	arg = (t_routine_arg *)argument;
	wait_all_threads(arg->sim);
	//set_timev(&arg->philosopher->mutex, &arg->philosopher->last_eat_timestamp, timev_get_curr());
	// TODO (?) evens sleep for 1?
	if (arg->philosopher->index % 2 == 0)
		sleep_ms(1, arg->sim);
	while (!is_sim_finished(arg->sim))
	{
		// Wait to eat
		pthread_mutex_lock(&arg->forks[get_first_fork_idx(arg->philosopher, arg->fork_count)]);
		print_msg("has taken a fork", arg->sim, arg->philosopher);
		pthread_mutex_lock(&arg->forks[get_second_fork_idx(arg->philosopher, arg->fork_count)]);
		print_msg("has taken a fork", arg->sim, arg->philosopher);
		
		// Eat
		arg->philosopher->state = STATE_EATING;
		print_msg("is eating", arg->sim, arg->philosopher);
		arg->philosopher->num_times_ate++;
		if (gettimeofday(&arg->philosopher->last_eat_timestamp, NULL) == -1)
			printf("Gettimeofday failed\n");
		sleep_ms(arg->sim->time_to_eat, arg->sim);

		pthread_mutex_unlock(&arg->forks[get_first_fork_idx(arg->philosopher, arg->fork_count)]);
		pthread_mutex_unlock(&arg->forks[get_second_fork_idx(arg->philosopher, arg->fork_count)]);
		
		// Think
		arg->philosopher->state = STATE_THINKING;
		print_msg("is thinking", arg->sim, arg->philosopher);
		
		// Sleep
		arg->philosopher->state = STATE_SLEEPING;
		print_msg("is sleeping", arg->sim, arg->philosopher);
		sleep_ms(arg->sim->time_to_sleep, arg->sim);
	}
	// check if any locks are left 
	// 
	return (argument);
}
