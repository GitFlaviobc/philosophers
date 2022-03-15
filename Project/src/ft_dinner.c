/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dinner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:12:50 by fbonini           #+#    #+#             */
/*   Updated: 2022/03/15 12:30:59 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_dinner_is_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(philo->mem->lock_dinner);
	if (philo->mem->died)
		end = 1;
	else
		end = 0;
	pthread_mutex_unlock(philo->mem->lock_dinner);
	return (end);
}

void	*ft_check_dinner(void *ptr)
{
	t_philo	*philos;
	long	current_time;
	long	death_time;
	long	last_meal;
	int		i;

	philos = (t_philo *)ptr;
	death_time = philos->mem->time_to_die;
	while (!ft_all_ate(philos))
	{
		i = 0;
		while (i < philos->mem->total_philos)
		{
			current_time = ft_timer(philos->mem->start_clock);
			last_meal = ft_get_last_meal(&philos[i]);
			if (current_time - last_meal > death_time)
			{
				ft_philo_died(&philos[i]);
				return (NULL);
			}
			i++;
		}
		ft_wait_time(1);
	}
	return (NULL);
}

void	*ft_dinner(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->mem->total_philos == 1)
	{
		pthread_mutex_lock(philo->fork_right);
		ft_get_print(philo);
		pthread_mutex_unlock(philo->fork_right);
		return (NULL);
	}
	if (philo->pos % 2)
		ft_wait_time(5);
	while (!ft_dinner_is_over(philo))
	{
		ft_philo_eat(philo);
		if (ft_get_eaten_times(philo) == philo->mem->must_eat)
			return (NULL);
		ft_philo_sleep(philo);
		ft_philo_think(philo);
	}
	return (NULL);
}

void	ft_start_dinner(int total, t_philo *philos)
{
	pthread_t	checker;

	philos->mem->start_clock = ft_dinner_timer();
	ft_create_threads(total, philos, &checker);
	ft_join_threads(total, philos, &checker);
}
