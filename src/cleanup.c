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

int	error(char *msg)
{
	printf("Error, %s\n", msg);
	return (0);
}

int	free_mutexes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		pthread_mutex_destroy(&info->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->ate_lock);
	pthread_mutex_destroy(&info->write_lock);
	pthread_mutex_destroy(&info->die_lock);

	return (0);
}

int	join_threads(t_info *info, t_philo philo[200])
{
	int	i;

	i = 0;
	while (i < info->num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			perror("pthread_join");
		i++;
	}
	return (0);
}
