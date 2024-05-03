/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:37:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/04/19 19:51:12 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
   Subtract time `y` from time `x`,
   write the result into the `result` time struct,
   return 0 if success, non-zero if failure.
*/
int	timev_subt(struct timeval *result, struct timeval *x, struct timeval *y)
{
	struct timeval	xx;
	struct timeval	yy;
	
	xx = *x;
	yy = *y;
	x = &xx;
	y = &yy;
	if (x->tv_usec > 999999)
	{
		x->tv_sec += x->tv_usec / 1000000;
		x->tv_usec %= 1000000;
	}
	if (y->tv_usec > 999999)
	{
		y->tv_sec += y->tv_usec / 1000000;
		y->tv_usec %= 1000000;
	}
	result->tv_sec = x->tv_sec - y->tv_sec;
	if ((result->tv_usec = x->tv_usec - y->tv_usec) < 0)
	{
		result->tv_usec += 1000000;
		result->tv_sec--;
	}
	return (result->tv_sec < 0);
}

/* Return the number of milliseconds in `duration` */
size_t	timev_to_ms(struct timeval duration)
{
	return (duration.tv_sec * 1000 + duration.tv_usec / 1000);
}

/*
   Get how many ms passed since the program started.
   Set `err_flag` of `sim` to 1 upon error.
*/
size_t	get_curr_program_time_ms(t_sim *sim)
{
	struct timeval	current;
	struct timeval	duration;

	if (gettimeofday(&current, NULL) != 0)
	{
		sim->err_flag = 1;
		return (0);
	}
	if (timev_subt(&duration, &current, &sim->start_timestamp) != 0)
	{
		sim->err_flag = 1;
		return (0);
	}
	return (timev_to_ms(duration));
}
