/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:30:29 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/21 19:27:14 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_takeforks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->id]);
	if (!printmsg(philo->info, philo, 'f'))
		return (0);
	pthread_mutex_lock(&philo->info->fork[(philo->id + 1) \
	% philo->info->num_of_philos]);
	if (!printmsg(philo->info, philo, 'f'))
		return (0);
	return (1);
}

int	ph_eat(t_philo *philo)
{
	if (philo->info->num_of_philos < 2)
		return ((void)pthread_mutex_unlock(&philo->info->fork[philo->id]), 1);
	philo->last_ate = get_current_time();
	if (!printmsg(philo->info, philo, 'e'))
		return (0);
	ft_usleep(200);
	pthread_mutex_lock(&philo->info->ate_lock);
	philo->info->ateed++;
	pthread_mutex_unlock(&philo->info->ate_lock);
	pthread_mutex_unlock(&philo->info->fork[philo->id]);
	pthread_mutex_unlock(&philo->info->fork[(philo->id + 1) \
	% philo->info->num_of_philos]);
	return (1);
}

int	ph_sleep(t_philo *philo)
{
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
