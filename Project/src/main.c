/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:01:59 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/15 12:01:36 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_mem	mem;
	t_mutex	*forks;
	t_philo	*philos;

	ft_parse_args(argc, argv);
	ft_pre_dinner(&mem, &forks, &philos, argv);
	ft_start_dinner(mem.total_philos, philos);
	ft_end_dinner(&mem, forks, philos);
	return (0);
}
