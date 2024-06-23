/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 19:29:53 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, t_sim *sim, t_philo *p)
{
	pthread_mutex_lock(&sim->write_mutex);
	size_t curr_time = get_curr_program_time_ms(sim);
	if (!is_sim_finished(sim))
		printf("%zu %d %s\n", curr_time, p->index + 1, msg);
	pthread_mutex_unlock(&sim->write_mutex);
}
