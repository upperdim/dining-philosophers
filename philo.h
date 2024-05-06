/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:30 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/06 18:58:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
// # include "../lib/my_time/my_time.h"
# include "philosopher.h"

# define TRUE 1
# define FALSE 0

/* Return types for some functions */
# define FAIL -1
# define SUCCESS 0

/* Status of the fork */
# define FORK_TAKEN 101
# define FORK_FREE 102

/* If assigned to the meal_limit field of `sim`, implies there is no meal limt*/
# define NO_MEAL_LIMIT -200

/* Data for the simulation */
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

/*
   Argument that will be passed to the routine function that will be run by
   threads of each philosopher.
*/
typedef struct routine_arg
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*forks;
	int				fork_count;
	t_sim			*sim;
}	t_routine_arg;

/* Operation code (type) for safe thread and safe mutex functions */
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

/* Time */
size_t	get_curr_program_time_ms(t_sim *sim);
size_t	timev_to_ms(struct timeval duration);
int		timev_subt(struct timeval *reslt, struct timeval *x, struct timeval *y);
int		timev_cmp(struct timeval t1, struct timeval t2);
void	timev_add_ms(struct timeval *result, struct timeval *tv, int ms);

/* Safe functions */
void	*safe_malloc(size_t bytes);
void	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
void	safe_thread_handle( \
pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode);

/* Utils */
void	error_exit(const char *err_msg);

#endif