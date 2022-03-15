/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:18:31 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/15 16:08:02 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(philo->lock_meal_time);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(philo->lock_meal_time);
	return (last_meal);
}

void	ft_set_meal_time(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meal_time);
	philo->last_meal = ft_timer(philo->mem->start_clock);
	pthread_mutex_unlock(philo->lock_meal_time);
}

long	ft_dinner_timer(void)
{
	struct timeval	time;
	long			time_sec;
	long			time_mili;
	long			time_micro;

	gettimeofday(&time, NULL);
	time_sec = time.tv_sec;
	time_micro = time.tv_usec;
	time_mili = (time_sec * 1000) + (time_micro / 1000);
	return (time_mili);
}

long	ft_timer(long dinner_start)
{
	long	current_time;
	long	time_passed;

	current_time = ft_dinner_timer();
	time_passed = current_time - dinner_start;
	return (time_passed);
}

void	ft_wait_time(int time_to_wait)
{
	long	time;
	long	i;

	time = ft_dinner_timer();
	i = ft_dinner_timer();
	while (i - time < (long)time_to_wait)
	{
		usleep(10);
		i = ft_dinner_timer();
	}
}
