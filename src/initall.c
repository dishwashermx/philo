/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:06:57 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/07 13:06:57 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkargs(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) > 200)
		return (0);
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) < 0)
			return (0);
		if (ft_atol(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	if (ft_isdigitarray(argv) == 0)
		return (0);
	return (1);
}

void	init_values(int argc, char **argv, t_info *info)
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atol(argv[2]);
	info->time_to_eat = ft_atol(argv[3]);
	info->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		info->num_times_to_eat = ft_atoi(argv[5]);
	else
		info->num_times_to_eat = -1;
	info->dieded = 0;
	info->ateed = 0;
	info->timestart = get_current_time();
}

void	init_mutex(t_info *info, t_philo philo[200])
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
	{
		philo[i].id = i;
		philo[i].info = info;
		philo[i].last_ate = get_current_time();
		if (pthread_mutex_init(&info->fork[i], NULL))
			return ;
	}
	if (pthread_mutex_init(&info->die_lock, NULL))
		return ;
	if (pthread_mutex_init(&info->ate_lock, NULL))
		return ;
	if (pthread_mutex_init(&info->write_lock, NULL))
		return ;
}

void	init_threads(t_info *info, t_philo philo[200])
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
		{
			perror("pthread_create");
			return ;
		}
	}
}

int	initall(int argc, char **argv, t_info *info, t_philo philo[200])
{
	if (checkargs(argc, argv) == 0)
		return (error("Invalid Arguments"));
	init_values(argc, argv, info);
	init_mutex(info, philo);
	init_threads(info, philo);
	return (0);
}
