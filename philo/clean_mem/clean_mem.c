/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:30:20 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/05 23:15:54 by dide-alm         ###   ########.fr       */
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

int	clean_memory(t_philos *philos, pthread_mutex_t *mutex, int *fork_i, int n_philos)
{
	if (mutex)
		clean_mutex(mutex, n_philos);
	if (philos)
		free(philos);
	if (fork_i)
		free(fork_i);
	return (1);
}
