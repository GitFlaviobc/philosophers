/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:16:41 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/15 11:16:55 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_get_print(t_philo *philo)
{
	long		current_time;
	t_printer	*act_print[TOTAL_ACTIONS];

	act_print[FORK] = ft_print_fork;
	act_print[EAT] = ft_print_eat;
	act_print[SLEEP] = ft_print_sleep;
	act_print[THINK] = ft_print_think;
	act_print[DIE] = ft_print_die;
	current_time = ft_timer(philo->mem->start_clock);
	pthread_mutex_lock(philo->mem->lock_print);
	if (!ft_dinner_is_over(philo))
		act_print[philo->action](current_time, philo->pos);
	else if (philo->action == DIE)
		act_print[philo->action](current_time, philo->pos);
	pthread_mutex_unlock(philo->mem->lock_print);
}
