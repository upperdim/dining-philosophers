/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:30 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/24 16:39:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

/* Return types for some functions */
# define FAIL -1
# define SUCCESS 0
# define SUCCESS_EXIT 1

/* Status of the fork */
# define FORK_TAKEN 101
# define FORK_FREE 102

/* If assigned to the meal_limit field of `sim`, implies there is no meal limt*/
# define NO_MEAL_LIMIT -200

# define STATE_NA -1
# define STATE_THINKING 0
# define STATE_EATING 1
# define STATE_SLEEPING 2

typedef struct s_philo
{
	int				index;
	int				dead;
	int				error_flag;
	int				state;
	struct timeval	last_eat_timestamp;
	int				num_times_ate;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}	t_philo;

/* Struct prototypes */
struct					s_sim;
typedef struct s_sim	t_sim;

/*
   Argument that will be passed to the routine function that will be run by
   threads of each philosopher.
*/
typedef struct s_routine_arg
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	int				fork_count;
	t_sim			*sim;
}	t_routine_arg;

/* Data for the simulation */
typedef struct s_sim
{
	int				num_of_philos;
	int				time_to_die_wo_eating;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_limit;
	int				meal_limit_exists;
	struct timeval	start_timestamp;
	int				err_flag;
	int				is_all_threads_ready;
	int				finished;
	pthread_mutex_t	sim_mutex;
	pthread_mutex_t	write_mutex;
	pthread_t		observer_thread;
	t_routine_arg	*philo_r_args_arr;
	t_routine_arg	*observer_r_arg;
}	t_sim;

/* Threads */
void	set_int(pthread_mutex_t *mutex, int *dest, int val);
int		get_int(pthread_mutex_t *mutex, int *dest);
void	print_msg(char *str, t_sim *sim, t_philo *p);
void	print_msg_dbg(char *msg, t_sim *sim, t_philo *p, int fork_idx);
void	wait_all_threads(t_sim *sim);
int		is_sim_finished(t_sim *sim);

int		init_threads(t_sim *sim, t_philo *philos, pthread_mutex_t *forks);
void	join_threads(t_sim *sim, t_philo *philosophers);

void	*observe(void *argument);
void	*routine(void *argument);

/* Utils */
size_t	get_curr_program_time_ms(t_sim *sim);
size_t	timev_to_ms(struct timeval duration);
size_t	get_curr_time_ms(void);
void	sleep_ms(long sleep_duration_ms, t_sim *sim);

int		str_is_numeric(char *s);
long	ft_atoi_l(const char *str);

int		parse_args(int argc, char *argv[], t_sim *sim);

#endif