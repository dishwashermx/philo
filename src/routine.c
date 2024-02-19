/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 09:49:19 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/19 13:21:40 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philovoid)
{
	t_philo	*philo;

	philo = (t_philo *)(philovoid);
	pthread_mutex_lock(&philo->info->ate_lock);
	if (philo->info->ateed == 1)
		philo->info->ateed = 0;
	else
		philo->info->ateed = 1;
	pthread_mutex_unlock(&philo->info->ate_lock);
	return NULL;
}
