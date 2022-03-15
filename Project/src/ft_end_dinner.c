/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:23:19 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/16 12:23:09 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_four(t_mutex *t1, t_mutex *t2, t_mutex *t3, t_philo *t4)
{
	if (t1)
		free(t1);
	if (t2)
		free(t2);
	if (t3)
		free(t3);
	if (t4)
		free(t4);
}

void	ft_end_dinner(t_mem *mem, t_mutex *forks, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < mem->total_philos && forks)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	i = 0;
	while (i < mem->total_philos && philo)
	{
		if (philo[i].lock_meal_time)
			pthread_mutex_destroy(philo[i].lock_meal_time);
		if (philo[i].lock_meals)
			pthread_mutex_destroy(philo[i].lock_meals);
		ft_free_four(philo[i].lock_meal_time, philo[i].lock_meals, NULL, NULL);
		i++;
	}
	if (mem->lock_print)
		pthread_mutex_destroy(mem->lock_print);
	if (mem->lock_dinner)
		pthread_mutex_destroy(mem->lock_dinner);
	ft_free_four(mem->lock_print, mem->lock_dinner, forks, philo);
}

void	ft_fail_prep(t_mem *mem, t_mutex *forks, t_philo *philos)
{
	ft_end_dinner(mem, forks, philos);
	exit(EXIT_FAILURE);
}
