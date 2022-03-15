/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:19:40 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/16 16:46:20 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_philo_died(t_philo *philo)
{
	pthread_mutex_lock(philo->mem->lock_dinner);
	philo->mem->died = 1;
	philo->action = DIE;
	pthread_mutex_unlock(philo->mem->lock_dinner);
	ft_get_print(philo);
}

void	ft_philo_think(t_philo *philo)
{
	philo->action = THINK;
	ft_get_print(philo);
	usleep(50);
}

void	ft_philo_sleep(t_philo *philo)
{
	philo->action = SLEEP;
	ft_get_print(philo);
	ft_wait_time(philo->mem->time_to_sleep);
}
