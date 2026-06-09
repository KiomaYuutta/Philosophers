/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 03:10:08 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/29 03:10:08 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_mutex_t	*mutex;
	t_philos		*philos;
	t_data			data;
	int			*forks_i;

	philos = NULL;
	if (main_check(argc, argv))
		return (1);
	set_data(argv, &data);
	mutex = malloc(data.philo_cnt * sizeof(pthread_mutex_t));
	philos = malloc(data.philo_cnt * sizeof(t_philos));
	forks_i = malloc(data.philo_cnt * sizeof(int));
	if (!philos || !mutex || !forks_i)
		return (clean_memory(philos, mutex, forks_i, data.n_must_eat));
	set_philos(philos, data, mutex, forks_i);
	start_simulation(philos, data.philo_cnt);
	clean_memory(philos, mutex, forks_i, data.philo_cnt);
	return (0);
}
