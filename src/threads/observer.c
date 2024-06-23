/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:24:18 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 19:38:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Check if all philosophers reached the meal limit */
static int	meal_limit_check(t_sim *sim, t_philo *philosophers)
{
	int	i;
	int	num_philos_reached_limit;

	i = 0;
	num_philos_reached_limit = 0;
	while (i < sim->num_of_philos)
	{
		pthread_mutex_lock(&philosophers[i].mutex);
		if (philosophers[i].num_times_ate >= sim->meal_limit)
			++num_philos_reached_limit;
		pthread_mutex_unlock(&philosophers[i].mutex);
		++i;
	}
	if (num_philos_reached_limit >= sim->num_of_philos)
	{
		set_int(&sim->sim_mutex, &sim->finished, TRUE);
		return (1);
	}
	return (0);
}

static int	is_philosopher_dead(t_sim *sim, t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	if (p->state != STATE_EATING
		&& get_curr_time_ms() - timev_to_ms(p->last_eat_timestamp) 
		>= (size_t) sim->time_to_die_wo_eating)
	{
		pthread_mutex_unlock(&p->mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&p->mutex);
	return (FALSE);
}

/* Check if any philosopher died */
static int	death_check(t_sim *sim, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		if (is_philosopher_dead(sim, &philosophers[i]))
		{
			print_msg("died", sim, &philosophers[i]);
			set_int(&philosophers[i].mutex, &philosophers[i].dead, TRUE);
			set_int(&sim->sim_mutex, &sim->finished, TRUE);
			return (1);
		}
		++i;
	}
	return (0);
}

void	*observe(void *argument)
{
	t_routine_arg 	*arg;
	t_philo 		*philosophers_arr;

	arg = (t_routine_arg *)argument;
	philosophers_arr = arg->philosopher;
	while (1)
	{
		if (death_check(arg->sim, philosophers_arr))
			break ;
		if (arg->sim->meal_limit_exists
			&& meal_limit_check(arg->sim, philosophers_arr))
				break ;
	}
	return (argument);
}
