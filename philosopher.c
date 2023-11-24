/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:02:08 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/24 18:31:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philosopher_change_state(t_philosopher *p, int new_state)
{
	p->state = new_state;
	if (new_state == STATE_SLEEPING)
		ft_printf("%u %d is sleeping\n", timestampt, p->index + 1);
	else if (new_state == STATE_THINKING)
		ft_printf("%u %d is thinking\n", timestampt, p->index + 1);
	else if (new_state == STATE_EATING)
		ft_printf("%u %d is eating\n", timestampt, p->index + 1);
}

void	philosopher_die(t_philosopher *p)
{
	p->did_die = TRUE;
	ft_printf("%u %d died\n", timestampt, p->index + 1);
}

void	philosopher_take_fork(t_philosopher *p)
{
	p->has_fork = TRUE;
	ft_printf("%u %d has taken a fork\n", timestampt, p->index + 1);
}
