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
	t_info	info;
	t_philo	philo[200];

	initall(argc, argv, &info, philo);
	join_threads(&info, philo);
	free_mutexes(&info);
	return (0);
}

void	*routine(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)(philovoid);
	if (philo->id % 2 != 0)
		ft_usleep(philo->info->time_to_sleep);
	while (if_dead(philo))
	{
		if (!ph_takeforks(philo))
			break ;
		if (!ph_eat(philo))
			break ;
		if (!ph_sleep(philo))
			break ;
		if (!ph_think(philo))
			break ;
	}
	return (NULL);
}
