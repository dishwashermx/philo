/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:07:58 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/20 13:44:48 by ghwa             ###   ########.fr       */
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

void	printtimestamps(t_info *info, t_philo *philo, char code)
{
	size_t	time;
	char	*action;

	action = NULL;
	if (code == 'f')
		action = ft_strdup("has taken a fork");
	else if (code == 'e')
		action = ft_strdup("is eating");
	else if (code == 's')
		action = ft_strdup("is sleeping");
	else if (code == 't')
		action = ft_strdup("is thinking");
	else if (code == 'd')
		action = ft_strdup("died");
	time = get_current_time() - info->timestart;
	printf("%06zu %d %s\n", time, philo->id, action);
	free (action);
	return ;
}
