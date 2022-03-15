/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_dinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:06:37 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/16 12:07:34 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_args_to_mem(t_mem *mem, char **argv)
{
	mem->total_philos = ft_atoi(argv[1]);
	mem->time_to_die = ft_atoi(argv[2]);
	mem->time_to_eat = ft_atoi(argv[3]);
	mem->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		mem->must_eat = ft_atoi(argv[5]);
	else
		mem->must_eat = -1;
}

void	ft_alloc_mutexes(t_mem *mem, t_mutex **forks, t_philo **philos)
{
	mem->lock_print = (t_mutex *)malloc(sizeof(t_mutex) * 1);
	mem->lock_dinner = (t_mutex *)malloc(sizeof(t_mutex) * 1);
	if (mem->lock_print == NULL || mem->lock_dinner == NULL)
	{
		printf("Failed to alloc mutex!\n");
		ft_fail_prep(mem, *forks, *philos);
	}
	pthread_mutex_init(mem->lock_print, NULL);
	pthread_mutex_init(mem->lock_dinner, NULL);
}

void	ft_alloc_forks(t_mem *mem, t_mutex **forks, t_philo **philos)
{
	int	i;

	*forks = (t_mutex *) malloc(sizeof(t_mutex) * mem->total_philos);
	if (*forks == NULL)
	{
		printf("Failed to alloc forks!\n");
		ft_fail_prep(mem, *forks, *philos);
	}
	i = 0;
	while (i < mem->total_philos)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
}

void	ft_alloc_philosophers(t_mem *mem, t_mutex **forks, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * mem->total_philos);
	if (*philos == NULL)
	{
		printf("Failed to alloc philosophers!\n");
		ft_fail_prep(mem, *forks, *philos);
	}
	i = 0;
	while (i < mem->total_philos)
	{
		(*philos)[i].fork_right = &(*forks)[i];
		(*philos)[i].fork_left = &(*forks)[i + 1];
		(*philos)[i].pos = i + 1;
		(*philos)[i].eaten_times = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].mem = mem;
		(*philos)[i].action = FORK;
		(*philos)[i].lock_meals = (t_mutex *)malloc(sizeof(t_mutex) * 1);
		pthread_mutex_init((*philos)[i].lock_meals, NULL);
		(*philos)[i].lock_meal_time = (t_mutex *)malloc(sizeof(t_mutex) * 1);
		pthread_mutex_init((*philos)[i].lock_meal_time, NULL);
		i++;
	}
	(*philos)[--i].fork_left = &(*forks)[0];
}

void	ft_pre_dinner(t_mem *mem, t_mutex **fork, t_philo **philos, char **argv)
{
	memset(mem, 0, sizeof(t_mem));
	memset(philos, 0, sizeof(t_philo *));
	memset(fork, 0, sizeof(t_mutex *));
	ft_args_to_mem(mem, argv);
	ft_alloc_mutexes(mem, fork, philos);
	ft_alloc_forks(mem, fork, philos);
	ft_alloc_philosophers(mem, fork, philos);
}
