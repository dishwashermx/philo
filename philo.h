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

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

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
	size_t			timestart;
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
void			*routine(void *philo);
int				ft_isdigitarray(char **str);
long			ft_atol(const char *str);
int				ft_atoi(const char *str);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_usleep(size_t milliseconds);
size_t			get_current_time(void);
void			printtimestamps(t_info *info, t_philo *philo, char code);
#endif