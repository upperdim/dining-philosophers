/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 15:43:16 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *argument)
{
	t_routine_arg	*arg;

	arg = (t_routine_arg *)argument;
	wait_all_threads(arg->sim);
	//set_timev(&arg->philosopher->mutex, &arg->philosopher->last_eat_timestamp, timev_get_curr());
	// TODO (?) evens sleep for 1?
	if (arg->philo->index % 2 == 0)
		sleep_ms(1, arg->sim);
	while (!is_sim_finished(arg->sim))
	{
		philo_eat(arg);
		philo_think(arg);
		philo_sleep(arg);
	}
	// check if any locks are left 
	// 
	return (argument);
}
