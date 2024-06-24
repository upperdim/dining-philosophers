/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 19:46:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	get_first_fork_idx(t_routine_arg *arg)
// {
// 	if (arg->philo->index == arg->sim->num_of_philos - 1)
// 	{
// 		return (arg->philo->index);
// 	}
// 	else
// 	{
// 		return ((arg->philo->index + 1) % arg->fork_count);
// 	}
// }

// int	get_second_fork_idx(t_routine_arg *arg)
// {
// 	if (arg->philo->index == arg->sim->num_of_philos - 1)
// 	{
// 		return ((arg->philo->index + 1) % arg->fork_count);
// 	}
// 	else
// 	{
// 		return (arg->philo->index);
// 	}
// }

static void	philo_eat(t_routine_arg *arg)
{
	pthread_mutex_lock(&arg->forks[arg->philo->index]);
	// pthread_mutex_lock(&arg->forks[get_first_fork_idx(arg)]);
	print_msg("has taken a fork", arg->sim, arg->philo);
	if (arg->fork_count == 1)
	{
		pthread_mutex_unlock(&arg->forks[arg->philo->index]);
		return ;
	}
	pthread_mutex_lock(&arg->forks[(arg->philo->index + 1) % arg->fork_count]);
	// pthread_mutex_lock(&arg->forks[get_second_fork_idx(arg)]);
	print_msg("has taken a fork", arg->sim, arg->philo);
	// arg->philo->state = STATE_EATING;
	set_int(&arg->philo->state_mutex, &arg->philo->state, STATE_EATING);
	print_msg("is eating", arg->sim, arg->philo);
	arg->philo->num_times_ate++;
	if (gettimeofday(&arg->philo->last_eat_timestamp, NULL) == -1)
		printf("Gettimeofday failed\n");
	sleep_ms(arg->sim->time_to_eat, arg->sim);
	pthread_mutex_unlock(&arg->forks[arg->philo->index]);
	pthread_mutex_unlock(\
	&arg->forks[(arg->philo->index + 1) % arg->fork_count]);
	// pthread_mutex_unlock(&arg->forks[get_second_fork_idx(arg)]);
	// pthread_mutex_unlock(&arg->forks[get_first_fork_idx(arg)]);
}

static void	philo_think(t_routine_arg	*arg)
{
	set_int(&arg->philo->state_mutex, &arg->philo->state, STATE_THINKING);
	print_msg("is thinking", arg->sim, arg->philo);
}

static void	philo_sleep(t_routine_arg	*arg)
{
	set_int(&arg->philo->state_mutex, &arg->philo->state, STATE_SLEEPING);
	print_msg("is sleeping", arg->sim, arg->philo);
	sleep_ms(arg->sim->time_to_sleep, arg->sim);
}

void	*routine(void *argument)
{
	t_routine_arg	*arg;

	arg = (t_routine_arg *)argument;
	wait_all_threads(arg->sim);
	if (arg->philo->index % 2 == 0)
		sleep_ms(1, arg->sim);
	while (!is_sim_finished(arg->sim))
	{
		philo_eat(arg);
		philo_think(arg);
		philo_sleep(arg);
	}
	return (argument);
}
