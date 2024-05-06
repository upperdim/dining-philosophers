/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:43:26 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/06 22:49:29 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Set value `val` to integer `dest` which is protected by `mutex` */
void	set_int(pthread_mutex_t *mutex, int *dest, int val)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = val;
	safe_mutex_handle(mutex, UNLOCK);
}

/* Get value of integer `dest` which is protected by `mutex` */
int	get_int(pthread_mutex_t *mutex, int *dest)
{
	int	ret;

	safe_mutex_handle(mutex, LOCK);
	ret = *dest;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

/* Set value `val` to long `dest` which is protected by `mutex` */
void	set_long(pthread_mutex_t *mutex, long *dest, int val)
{
	safe_mutex_handle(mutex, LOCK);
	*dest = val;
	safe_mutex_handle(mutex, UNLOCK);
}

/* Get value of integer `dest` which is protected by `mutex` */
int	get_long(pthread_mutex_t *mutex, long *dest)
{
	long	ret;

	safe_mutex_handle(mutex, LOCK);
	ret = *dest;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}
