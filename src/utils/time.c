/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:37:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 16:30:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Return the number of milliseconds in `duration` */
size_t	timev_to_ms(struct timeval duration)
{
	return (duration.tv_sec * 1000 + duration.tv_usec / 1000);
}

size_t	get_curr_program_time_ms(t_sim *sim)
{
	struct timeval	current_tv;
	size_t			current_ms;

	if (gettimeofday(&current_tv, NULL) != 0)
		printf("Gettimeofday failed\n");
	current_ms = timev_to_ms(current_tv);
	return (current_ms - timev_to_ms(sim->start_timestamp));
}

size_t	get_curr_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		printf("Gettimeofday failed\n");
	return timev_to_ms(tv);
}

void	sleep_ms(long sleep_duration_ms, t_sim *sim)
{
	size_t	start_us;

	start_us = get_curr_time_ms();
	while (get_curr_time_ms() - start_us < (size_t) sleep_duration_ms)
	{
		if (is_sim_finished(sim))
			return ;
		usleep(500);
	}
}
