/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:01:24 by tunsal            #+#    #+#             */
/*   Updated: 2023/11/24 18:37:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "philosopher.h"

void	init_philosophers()
{

}

int	main(int argc, char *argv[])
{
	int				*forks;
	t_philosopher	*philosophers;
	t_args			args;
	size_t			i;

	if (argc != 5 || argc != 6)
		return (1);
	if (!str_is_numeric(argv[1]) || !str_is_numeric(argv[2]) 
		|| !str_is_numeric(argv[3]) || !str_is_numeric(argv[4])
		|| (argc == 6 && !str_is_numeric(argv[5])))
		return (1);
	args.num_of_philos = atoi(argv[1]);
	args.time_to_die_wo_eating = atoi(argv[1]);
	args.time_takes_to_eat = atoi(argv[1]);
	args.time_takes_to_sleep = atoi(argv[1]);
	if (argc == 6)
		args.num_of_times_must_eat = atoi(argv[1]);
	philosophers = (t_philosopher *) \
	malloc(args.num_of_philos * sizeof(t_philosopher));
	if (philosophers == NULL)
		return (1);
	forks = (int *) malloc(args.num_of_philos * sizeof(int));
	if (forks == NULL)
		return (1);
	i = 0;
	while (i < args.num_of_philos)
	{
		philosophers->index = i;
		forks[i] = FORK_FREE;
		++i;
	}

	return (0);
}
