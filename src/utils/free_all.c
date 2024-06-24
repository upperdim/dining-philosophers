/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:30:27 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 17:43:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philos, pthread_mutex_t *forks, t_sim *sim)
{
	int	i;

	if (philos != NULL)
		free(philos);
	if (forks != NULL)
		free(forks);
	i = 0;
	while (i < sim->num_of_philos)
	{
		++i;
	}
	
}
