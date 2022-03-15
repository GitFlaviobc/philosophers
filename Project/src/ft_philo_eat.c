/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:16:14 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/16 12:08:43 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_add_eaten_times(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meals);
	philo->eaten_times++;
	pthread_mutex_unlock(philo->lock_meals);
}

int	ft_get_eaten_times(t_philo *philo)
{
	int	times;

	pthread_mutex_lock(philo->lock_meals);
	times = philo->eaten_times;
	pthread_mutex_unlock(philo->lock_meals);
	return (times);
}

int	ft_all_ate(t_philo *philos)
{
	int	i;
	int	finished;

	finished = 0;
	i = 0;
	while (i < philos->mem->total_philos)
	{
		if (ft_get_eaten_times(&philos[i]) == philos->mem->must_eat)
			finished++;
		i++;
	}
	if (finished == philos->mem->total_philos)
		return (1);
	return (0);
}

void	ft_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	if (ft_dinner_is_over(philo))
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	philo->action = FORK;
	ft_get_print(philo);
	ft_get_print(philo);
	philo->action = EAT;
	ft_get_print(philo);
	ft_set_meal_time(philo);
	ft_wait_time(philo->mem->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	ft_add_eaten_times(philo);
}
