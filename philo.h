/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:35:02 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/02 17:04:34 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>

typedef struct s_philo
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
}					t_philo;

int				checkargs(int argc, char **argv);
int				initall(int argc, char **argv, t_philo *philo);
pthread_mutex_t	*init_mutexes(t_philo *philo, pthread_mutex_t *forks);

#endif