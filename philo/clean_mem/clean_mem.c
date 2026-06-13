/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:30:20 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/13 16:27:53 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_mutex(pthread_mutex_t *mutex, int n_philo)
{
	int	cnt;

	cnt = 0;
	while (cnt < n_philo)
		pthread_mutex_destroy(&(mutex[cnt++]));
	free (mutex);
}

int	clean_memory(t_philos *philos, pthread_mutex_t *mutex, int n_philos)
{
	if (mutex)
		clean_mutex(mutex, n_philos);
	if (philos->eaten_lock)
	{
		pthread_mutex_destroy(philos->eaten_lock);
		free(philos->eaten_lock);
	}
	if (philos->forks_i)
		free(philos->forks_i);
	if (philos)
		free(philos);
	return (1);
}
