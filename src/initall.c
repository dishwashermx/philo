/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:06:57 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/07 13:06:57 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_values(int argc, char **argv, t_philo *philo)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->num_times_to_eat = ft_atoi(argv[5]);
}

int	initall(int argc, char **argv, t_philo *philo)
{
	init_values(argc, argv, philo);
	
	return (0);
}