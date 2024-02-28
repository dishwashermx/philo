/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:29 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/26 14:00:08 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_takeforks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->info->fork[philo->id]) == 0)
	{
		if (!printmsg(philo->info, philo, 'f'))
			return (0);
	}
	if (philo->info->num_of_philos == 1)
	{
		return (1);
	}
	else if (pthread_mutex_lock(&philo->info->fork[(philo->id + 1) \
	% philo->info->num_of_philos]) == 0)
	{
		if (!printmsg(philo->info, philo, 'f'))
			return (0);
	}
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
	pthread_mutex_unlock(&philo->info->fork[(philo->id + 1) \
	% philo->info->num_of_philos]);
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
