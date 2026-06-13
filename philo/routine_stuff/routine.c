/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:08 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/13 16:50:28 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_spaghetti(t_philos *philos)
{
	grab_forks(philos);
	if (philos->someone_died)
	{
		leave_forks(philos);
		return ;
	}
	log_timestamp(philos, philos->log_lock, "is eating", 0);
	philos->last_time_eat = get_time_ms();
	precise_sleep(philos->time_to_eat);
	leave_forks(philos);
}

void	tink(t_philos *philos)
{
	if (philos->someone_died)
		return ;
	log_timestamp(philos, philos->log_lock, "is thinking", 0);
	precise_sleep(1);
}

void	mimir(t_philos *philos)
{
	if (philos->someone_died)
		return ;
	log_timestamp(philos, philos->log_lock, "is sleeping", 0);
	precise_sleep(philos->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philos	*philos;

	philos = arg;
	while (1)
	{
		eat_spaghetti(philos);
		tink(philos);
		mimir(philos);
		if (philos->someone_died)
			return (NULL);
		pthread_mutex_lock(philos->eaten_lock);
		if (philos->limit)
			philos->meny_eaten++;
		if (*(philos->leave))
		{
			pthread_mutex_unlock(philos->eaten_lock);
			return (NULL);
		}
		pthread_mutex_unlock(philos->eaten_lock);
		
	}
	return (NULL);
}
