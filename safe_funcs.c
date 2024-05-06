/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:47:34 by tunsal            #+#    #+#             */
/*   Updated: 2024/05/06 18:15:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		error_exit("Error with the malloc");
	return (ret);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		;
	else if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		error_exit("The value specified by mutex is invalid");
	else if (status == EINVAL && opcode == INIT)
		error_exit("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (status == EPERM)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_exit("The process cannot allocate enough memory to create another mutex.");
	else if (status == EBUSY)
		error_exit("Mutex is locked");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		;
	else if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of thread specifies the calling thread.");
}

void	safe_mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	int	ret;

	if (LOCK == opcode)
		ret = pthread_mutex_lock(mutex), opcode;
	else if (UNLOCK == opcode)
		ret = pthread_mutex_unlock(mutex), opcode;
	else if (INIT == opcode)
		ret = pthread_mutex_init(mutex, NULL), opcode;
	else if (DESTROY == opcode)
		ret = pthread_mutex_destroy(mutex), opcode;
	else
	{
		printf("Error: Invalid opcode in safe_mutex_handle()\n");
		exit(EXIT_FAILURE);
	}
	handle_mutex_error(ret, opcode);
}

void	safe_thread_handle\
(pthread_t *thread, void *(*foo)(void *), void *data, t_opcode opcode)
{
	int	ret;

	if (CREATE == opcode)
		ret = pthread_create(thread, NULL, foo, data);
	else if (JOIN == opcode)
		ret = pthread_join(*thread, NULL);
	else if (DETACH == opcode)
		ret = pthread_detach(*thread);
	else
	{
		printf("Error: Invalid opcode in safe_thread_handle()\n");
		exit(EXIT_FAILURE);
	}
	handle_thread_error(ret, opcode);
}
