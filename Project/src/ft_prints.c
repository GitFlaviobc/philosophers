/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:23:28 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/15 14:54:47 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_fork(long time, int pos)
{
	printf("%ld %d has taken a fork\n", time, pos);
}

void	ft_print_eat(long time, int pos)
{
	printf("%ld %d is eating\n", time, pos);
}

void	ft_print_sleep(long time, int pos)
{
	printf("%ld %d is sleeping\n", time, pos);
}

void	ft_print_think(long time, int pos)
{
	printf("%ld %d is thinking\n", time, pos);
}

void	ft_print_die(long time, int pos)
{
	printf("%ld %d died\n", time, pos);
}
