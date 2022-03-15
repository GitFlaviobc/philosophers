/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:03:14 by fbonini           #+#    #+#             */
/*   Updated: 2022/02/11 16:15:08 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_valid_arg(char *str)
{
	int		i;
	size_t	numb;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	numb = ft_atol(str);
	if (numb > 2147483647 || numb == 0)
		return (0);
	return (1);
}

void	ft_parse_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error\nPhilosophers uses 5 or 6 args\n");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		if (!ft_valid_arg(argv[i]))
		{
			printf("Error\nInvalid format for argv %d\n", i);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
