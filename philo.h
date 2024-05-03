/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:30 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/02 17:05:18 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> 
# include <sys/time.h>
# include <pthread.h>
// # include "../lib/my_time/my_time.h"
# include "philosopher.h"


# define TRUE 1
# define FALSE 0

# define FAIL -1
# define SUCCESS 0

# define FORK_TAKEN 101
# define FORK_FREE 102

# define NO_LIMIT -200

typedef struct sim
{
	int				num_of_philos;
	int				time_to_die_wo_eating;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_limit;
	struct timeval	start_timestamp;
	int				err_flag;
}	t_sim;

typedef struct routine_arg
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	int				fork_count;
	t_sim			*sim;
}	t_routine_arg;

/* Time */
size_t	get_curr_program_time_ms(t_sim *sim);
size_t	timev_to_ms(struct timeval duration);
int		timev_subt(struct timeval *reslt, struct timeval *x, struct timeval *y);

#endif