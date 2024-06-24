/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 16:46:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *msg, t_sim *sim, t_philo *p)
{
	size_t	curr_time;

	pthread_mutex_lock(&sim->write_mutex);
	curr_time = get_curr_program_time_ms(sim);
	if (!is_sim_finished(sim))
		printf("%zu %d %s\n", curr_time, p->index + 1, msg);
	pthread_mutex_unlock(&sim->write_mutex);
}

// void	print_msg_dbg(char *msg, t_sim *sim, t_philo *p, int fork_idx)
// {
// 	pthread_mutex_lock(&sim->write_mutex);
// 	size_t curr_time = get_curr_program_time_ms(sim);
// 	if (!is_sim_finished(sim))
// 		printf("%5zu %d %s %d\n", curr_time, p->index + 1, msg, fork_idx + 1);
// 	pthread_mutex_unlock(&sim->write_mutex);
// }
