/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:07:58 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/21 19:19:52 by ghwa             ###   ########.fr       */
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

int	ph_died(t_philo *philo, t_info *info)
{
	size_t	time;

	time = get_current_time() - info->timestart;
	pthread_mutex_lock(&philo->info->write_lock);
	printf("%06zu %d died\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->info->write_lock);
	pthread_mutex_lock(&philo->info->die_lock);
	philo->info->dieded++;
	pthread_mutex_unlock(&philo->info->die_lock);
	return (0);
}

int	printmsg(t_info *info, t_philo *philo, char code)
{
	size_t	time;
	char	*action;

	if (get_current_time() - philo->last_ate > philo->info->time_to_die || \
	code == 'd')
		return (ph_died(philo, info));
	action = NULL;
	if (code == 'f')
		action = ft_strdup("has taken a fork");
	else if (code == 'e')
		action = ft_strdup("is eating");
	else if (code == 's')
		action = ft_strdup("is sleeping");
	else if (code == 't')
		action = ft_strdup("is thinking");
	time = get_current_time() - info->timestart;
	pthread_mutex_lock(&philo->info->write_lock);
	printf("%06zu %d %s\n", time, philo->id + 1, action);
	pthread_mutex_unlock(&philo->info->write_lock);
	free (action);
	return (1);
}

int	if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->die_lock);
	if (philo->info->dieded > 0)
		return (pthread_mutex_unlock(&philo->info->die_lock));
	pthread_mutex_unlock(&philo->info->die_lock);
	pthread_mutex_lock(&philo->info->ate_lock);
	if (philo->info->num_times_to_eat > 0 && philo->info->ateed >= \
	philo->info->num_times_to_eat * philo->info->num_of_philos)
		return (pthread_mutex_unlock(&philo->info->ate_lock));
	pthread_mutex_unlock(&philo->info->ate_lock);
	return (1);
}
