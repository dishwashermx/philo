/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:47:23 by ghwa              #+#    #+#             */
/*   Updated: 2024/02/02 16:47:23 by ghwa             ###   ########.fr       */
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
		if (ft_atoi(argv[i++]) < 0)
			return (0);
	}
	if (ft_isdigitarray(argv) == 0)
		return (0);
	return (1);
}