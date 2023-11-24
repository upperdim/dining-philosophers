/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:30 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/24 18:31:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "philosophers.h"

# define STATE_THINKING 0
# define STATE_EATING 1
# define STATE_SLEEPING 2

typedef struct philosopher
{
	int		index;
	int		did_die;
	int		has_fork;
	int		state;
	long	last_eat_timestamp;
}	t_philosopher;

#endif