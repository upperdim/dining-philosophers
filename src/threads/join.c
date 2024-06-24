/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:52:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 17:15:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Join threads together at the end of the simulation */
void	join_threads(t_sim *sim, t_philo *philosophers)
{
	int	i;

	i = 0;
	while (i < sim->num_of_philos)
	{
		pthread_join(philosophers[i].thread, NULL);
		++i;
	}
	pthread_join(sim->observer_thread, NULL);
}
