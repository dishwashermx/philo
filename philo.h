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

typedef struct s_generalinformation
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	die_lock;
	pthread_mutex_t	ate_lock;
	int				dieded;
	int				ateed;
}	t_info;

typedef struct s_philospher
{
	pthread_t		thread;
	int				id;
	t_info			*info;
}	t_philo;

int				initall(int argc, char **argv, \
t_info *info, t_philo philo[200]);
int				error(char *msg);
int				free_mutexes(t_info *info);
void			*routine(t_philo *philo);

#endif