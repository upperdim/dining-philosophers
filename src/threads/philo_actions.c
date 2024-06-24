/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:53:10 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 15:43:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_routine_arg *arg)
{
	pthread_mutex_lock(&arg->forks[arg->philo->index]);
	pthread_mutex_lock(&arg->forks[(arg->philo->index + 1) % arg->fork_count]);
	arg->philo->state = STATE_EATING;
	print_msg("is eating", arg->sim, arg->philo);
	arg->philo->num_times_ate++;
	if (gettimeofday(&arg->philo->last_eat_timestamp, NULL) == -1)
		printf("Gettimeofday failed\n");
	sleep_ms(arg->sim->time_to_eat, arg->sim);
	pthread_mutex_unlock(&arg->forks[arg->philo->index]);
	pthread_mutex_unlock(&arg->forks[(arg->philo->index + 1) % arg->fork_count]);
}

void	philo_think(t_routine_arg	*arg)
{
	arg->philo->state = STATE_THINKING;
	print_msg("is thinking", arg->sim, arg->philo);
}

void	philo_sleep(t_routine_arg	*arg)
{
	arg->philo->state = STATE_SLEEPING;
	print_msg("is sleeping", arg->sim, arg->philo);
	sleep_ms(arg->sim->time_to_sleep, arg->sim);
}
