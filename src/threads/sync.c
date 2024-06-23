/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:32:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 22:31:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_all_threads(t_sim *sim)
{
	while (!get_int(&sim->sim_mutex, &sim->is_all_threads_ready))
	{
		;
	}
}

int	is_sim_finished(t_sim *sim)
{
	return get_int(&sim->sim_mutex, &sim->finished);	
}
