/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:43:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/06/23 18:26:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Set value `val` to integer `dest` which is protected by `mutex` */
void	set_int(pthread_mutex_t *mutex, int *dest, int val)
{
	pthread_mutex_lock(mutex);
	*dest = val;
	pthread_mutex_unlock(mutex);
}

/* Get value of integer `dest` which is protected by `mutex` */
int	get_int(pthread_mutex_t *mutex, int *dest)
{
	int	ret;

	pthread_mutex_lock(mutex);
	ret = *dest;
	pthread_mutex_unlock(mutex);
	return (ret);
}
