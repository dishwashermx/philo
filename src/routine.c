/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:29 by ghwa              #+#    #+#             */
/*   Updated: 2025/08/04 17:24:55 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Guarded fork grabbing
int	ph_takeforks(t_philo *philo)
{
	int	left = philo->id;
	int	right = (philo->id + 1) % philo->info->num_of_philos;

	if (pthread_mutex_lock(&philo->info->fork[left]) != 0)
		return (0);
	if (!printmsg(philo->info, philo, 'f'))
		return (0);

	if (philo->info->num_of_philos == 1)
		return (1);

	if (pthread_mutex_lock(&philo->info->fork[right]) != 0)
	{
		pthread_mutex_unlock(&philo->info->fork[left]);
		return (0);
	}
	if (!printmsg(philo->info, philo, 'f'))
		return (0);

	return (1);
}

int	ph_eat(t_philo *philo)
{
	if (philo->info->num_of_philos == 1)
		return (1);

	pthread_mutex_lock(&philo->info->ate_lock);
	philo->last_ate = get_current_time();
	philo->info->ateed++;
	pthread_mutex_unlock(&philo->info->ate_lock);

	if (!printmsg(philo->info, philo, 'e'))
		return (0);

	ft_usleep(philo->info->time_to_eat);

	pthread_mutex_unlock(&philo->info->fork[philo->id]);
	pthread_mutex_unlock(&philo->info->fork[(philo->id + 1) % philo->info->num_of_philos]);

	return (1);
}

int	ph_sleep(t_philo *philo)
{
	if (philo->info->num_of_philos == 1)
		pthread_mutex_unlock(&philo->info->fork[philo->id]);

	if (!printmsg(philo->info, philo, 's'))
		return (0);

	ft_usleep(philo->info->time_to_sleep);
	return (1);
}

int	ph_think(t_philo *philo)
{
	if (!printmsg(philo->info, philo, 't'))
		return (0);
	return (1);
}
