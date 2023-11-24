/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:25 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/24 18:37:27 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>

# define TRUE 1
# define FALSE 0

# define FORK_TAKEN 1
# define FORK_FREE 0

typedef struct args
{
	int	num_of_philos;
	int	time_to_die_wo_eating;
	int	time_takes_to_eat;
	int	time_takes_to_sleep;
	int	num_of_times_must_eat;
}	t_args;

#endif