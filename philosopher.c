/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:08 by tunsal            #+#    #+#             */
/*   Updated: 2024/04/20 06:29:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_change_state(t_sim *sim, t_philosopher *p, int new_state)
{
	int	timestamp;
	
	p->state = new_state;
	timestamp = sim->start_timestamp - ;
	if (new_state == STATE_SLEEPING)
		ft_printf("%u %d is sleeping\n", timestamp, p->index + 1);
	else if (new_state == STATE_THINKING)
		ft_printf("%u %d is thinking\n", timestamp, p->index + 1);
	else if (new_state == STATE_EATING)
		ft_printf("%u %d is eating\n", timestamp, p->index + 1);
}    

void	philosopher_die(t_sim *sim, t_philosopher *p)
{
	int	timestampt;

	p->dead = TRUE;
	timestampt = sim->start_timestamp - ;
	ft_printf("%u %d died\n", timestampt, p->index + 1);
}

void	philosopher_take_fork(t_sim *sim, t_philosopher *p)
{
	int	timestampt;

	p->has_fork = TRUE;
	timestampt = sim->start_timestamp - ;
	ft_printf("%u %d has taken a fork\n", timestampt, p->index + 1);
}
