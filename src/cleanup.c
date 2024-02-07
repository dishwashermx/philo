/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:23:09 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/08 01:23:09 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_mutexes(t_philo *philo)
{
	int	i;
	
	i = 0;
	while (i < philo->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
	}
}

int	freeall(t_philo *philo)
{
	free_mutexes(philo);

	 for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
}