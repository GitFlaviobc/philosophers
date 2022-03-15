/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:15:13 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/15 09:15:26 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_threads(int total, t_philo *philos, pthread_t *checker)
{
	int	i;

	i = 0;
	while (i < total)
	{
		pthread_create(&philos[i].thread, NULL, &ft_dinner, &philos[i]);
		i++;
	}
	pthread_create(checker, NULL, &ft_check_dinner, philos);
}

void	ft_join_threads(int total, t_philo *philos, pthread_t *checker)
{
	int	i;

	i = 0;
	while (i < total)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(*checker, NULL);
}
