/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/03 15:45:07 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# define STATE_THINKING 0
# define STATE_EATING 1
# define STATE_SLEEPING 2

typedef struct philosopher
{
	int				index;
	int				dead;
	int				error_flag;
	// pthread_mutex_t	fork_left;
	// pthread_mutex_t	fork_right;
	int				state;
	struct timeval	last_eat_timestamp;
	int				num_times_ate;
	pthread_t		thread;
}	t_philosopher;

#endif