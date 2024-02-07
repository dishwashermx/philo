/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:53:30 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/02 17:07:03 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo;
	pthread_mutex_t	forks[ft_atoi(argv[1])];

	if (checkargs(argc, argv) == 0)
		ft_printf("ERROR\nInvalid Arguments");
	initall(argc, argv, &philo);
	init_mutexes(&philo, forks);
	return (0);
}
