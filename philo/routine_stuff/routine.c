/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:08 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/14 15:10:13 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_spaghetti(t_philos *philos)
{
	pthread_mutex_lock(philos->end_lock);
	if (*(philos->someone_died) || *(philos->leave))
	{
		leave_forks(philos);
		pthread_mutex_unlock(philos->end_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->end_lock);
	grab_forks(philos);
	log_timestamp(philos, philos->log_lock, "is eating", 0);
	philos->last_time_eat = get_time_ms();
	precise_sleep(philos->time_to_eat);
	leave_forks(philos);
	if (philos->limit)
		philos->meny_eaten++;
	return (0);
}

int	tink(t_philos *philos)
{
	pthread_mutex_lock(philos->end_lock);
	if (*(philos->someone_died) || *(philos->leave))
	{
		pthread_mutex_unlock(philos->end_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->end_lock);
	log_timestamp(philos, philos->log_lock, "is thinking", 0);
	precise_sleep(1);
	return (0);
}

int	mimir(t_philos *philos)
{
	long long	start;

	pthread_mutex_lock(philos->end_lock);
	if (*(philos->someone_died) || *(philos->leave))
	{
		pthread_mutex_unlock(philos->end_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->end_lock);
	log_timestamp(philos, philos->log_lock, "is sleeping", 0);
	start = get_time_ms();
	while ((get_time_ms() - start) < philos->time_to_sleep)
	{
		pthread_mutex_lock(philos->end_lock);
		if (*(philos->someone_died) || *(philos->leave))
		{
			pthread_mutex_unlock(philos->end_lock);
			return (1);
		}
		pthread_mutex_unlock(philos->end_lock);
		usleep(500);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (1)
	{
		if (eat_spaghetti(philos))
			return (NULL);
		if (tink(philos))
			return (NULL);
		if (mimir(philos))
			return (NULL);
	}
	return (NULL);
}
