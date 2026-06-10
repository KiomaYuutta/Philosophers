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
	pthread_mutex_t	*forks;
	pthread_mutex_t log_lock;
	t_philos		*philos;
	t_data			data;
	int			*forks_i;

	philos = NULL;
	if (main_check(argc, argv))
		return (1);
	set_data(argv, &data);
	pthread_mutex_init(&log_lock, NULL);
	data.log_lock = &log_lock;
	forks = malloc(data.philo_cnt * sizeof(pthread_mutex_t));
	philos = malloc(data.philo_cnt * sizeof(t_philos));
	forks_i = malloc(data.philo_cnt * sizeof(int));
	if (!philos || !forks || !forks_i)
		return (clean_memory(philos, forks, forks_i, data.philo_cnt));
	set_philos(philos, data, forks, forks_i);
	start_simulation(philos, &log_lock, data.philo_cnt);
	pthread_mutex_destroy(&log_lock);
	clean_memory(philos, forks, forks_i, data.philo_cnt);
	return (0);
}
