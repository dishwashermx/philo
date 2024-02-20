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
	ft_usleep(5000);
	free_mutexes(&info);
	return (0);
}

void	*routine(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)(philovoid);
	printtimestamps(philo->info, philo, 's');
	ft_usleep(200);
	return (NULL);
}
