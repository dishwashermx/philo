/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:07:58 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/26 14:08:01 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error("Time of Day"));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	printmsg(t_info *info, t_philo *philo, char code)
{
	size_t	time;

	pthread_mutex_lock(&philo->info->die_lock);
	if (philo->info->dieded > 0)
		return (pthread_mutex_unlock(&philo->info->die_lock));
	pthread_mutex_unlock(&philo->info->die_lock);
	pthread_mutex_lock(&philo->info->ate_lock);
	if (philo->info->done_ateing > 0)
		return (pthread_mutex_unlock(&philo->info->ate_lock));
	pthread_mutex_unlock(&philo->info->ate_lock);
	time = get_current_time() - info->timestart;
	pthread_mutex_lock(&philo->info->write_lock);
	if (code == 'f')
		printf("%06zu %d has taken a fork\n", time, philo->id + 1);
	else if (code == 'e')
		printf("%06zu %d is eating\n", time, philo->id + 1);
	else if (code == 's')
		printf("%06zu %d is sleeping\n", time, philo->id + 1);
	else if (code == 't')
		printf("%06zu %d is thinking\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->write_lock);
	return (1);
}

int	is_dead(t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->info->ate_lock);
	if ((get_current_time() - philo->last_ate) > philo->info->time_to_die)
	{
		pthread_mutex_unlock(&philo->info->ate_lock);
		time = get_current_time() - philo->info->timestart;
		pthread_mutex_lock(&philo->info->die_lock);
		philo->info->dieded++;
		pthread_mutex_unlock(&philo->info->die_lock);
		pthread_mutex_lock(&philo->info->write_lock);
		printf("%06zu %d died\n", time, philo->id + 1);
		pthread_mutex_unlock(&philo->info->write_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->ate_lock);
	return (0);
}

int	we_done(t_info *info)
{
	pthread_mutex_lock(&info->ate_lock);
	if (info->num_times_to_eat < 0)
	{
		pthread_mutex_unlock(&info->ate_lock);
		return (0);
	}
	if (info->ateed >= info->num_times_to_eat * info->num_of_philos)
	{
		info->done_ateing++;
		pthread_mutex_unlock(&info->ate_lock);
		return (1);
	}
	pthread_mutex_unlock(&info->ate_lock);
	return (0);
}
