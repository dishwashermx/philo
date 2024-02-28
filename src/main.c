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
	int		i;

	i = 0;
	if (initall(argc, argv, &info, philo) == 0)
		return (0);
	while (is_dead(&philo[i]) == 0 && we_done(&info) == 0)
	{
		i++;
		if (i == info.num_of_philos)
			i = 0;
	}
	join_threads(&info, philo);
	free_mutexes(&info);
	return (0);
}

void	*routine(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)(philovoid);
	if (philo->id % 2 != 0)
		ft_usleep(1);
	while (1)
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
