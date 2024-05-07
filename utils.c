/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:55:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/07 17:30:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_exit(const char *err_msg)
{
	if (err_msg != NULL)
		printf("%s\n", err_msg);
	exit(EXIT_FAILURE);
}

void	wait_all_threads(t_sim *sim)
{
	while (!get_int(&sim->sim_mutex, sim->is_all_threads_ready))
	{
		;
	}
}
