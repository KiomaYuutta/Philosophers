/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:44:22 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/14 15:21:09 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	grab_fork_right(t_philos *philos)
{
	while (1)
	{
		pthread_mutex_lock(philos->end_lock);
		if (*(philos->someone_died))
		{
			pthread_mutex_unlock(philos->end_lock);
			return (1);
		}
		pthread_mutex_unlock(philos->end_lock);
		pthread_mutex_lock(&(philos->forks_m[philos->r_hand]));
		if (!(philos->forks_i[philos->r_hand]))
		{
			philos->forks_i[philos->r_hand] = 1;
			pthread_mutex_unlock(&(philos->forks_m[philos->r_hand]));
			log_timestamp(philos, philos->log_lock, "has taken a fork", 0);
			return (0);
		}
		pthread_mutex_unlock(&(philos->forks_m[philos->r_hand]));
		usleep(300);
	}
	return (0);
}

int	grab_fork_left(t_philos *philos)
{
	while (1)
	{
		pthread_mutex_lock(philos->end_lock);
		if (*(philos->someone_died))
		{
			pthread_mutex_unlock(philos->end_lock);
			return (1);
		}
		pthread_mutex_unlock(philos->end_lock);
		pthread_mutex_lock(&(philos->forks_m[philos->l_hand]));
		if (!(philos->forks_i[philos->l_hand]))
		{
			philos->forks_i[philos->l_hand] = 1;
			pthread_mutex_unlock(&(philos->forks_m[philos->l_hand]));
			log_timestamp(philos, philos->log_lock, "has taken a fork", 0);
			return (0);
		}
		pthread_mutex_unlock(&(philos->forks_m[philos->l_hand]));
		usleep(300);
	}
	return (0);
}

int	grab_forks(t_philos *philos)
{
	pthread_mutex_lock(philos->end_lock);
	if (*(philos->someone_died))
	{
		pthread_mutex_unlock(philos->end_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->end_lock);
	if (philos->philo_id % 2 == 0)
	{
		if (grab_fork_right(philos) || grab_fork_left(philos))
			return (1);
	}
	else
	{
		if (grab_fork_left(philos) || grab_fork_right(philos))
			return (1);
	}
	return (0);
}

void	leave_forks(t_philos *philos)
{
	if (philos->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&(philos->forks_m[philos->r_hand]));
		philos->forks_i[philos->r_hand] = 0;
		pthread_mutex_unlock(&(philos->forks_m[philos->r_hand]));
		pthread_mutex_lock(&(philos->forks_m[philos->l_hand]));
		philos->forks_i[philos->l_hand] = 0;
		pthread_mutex_unlock(&(philos->forks_m[philos->l_hand]));
	}
	else
	{
		pthread_mutex_lock(&(philos->forks_m[philos->l_hand]));
		philos->forks_i[philos->l_hand] = 0;
		pthread_mutex_unlock(&(philos->forks_m[philos->l_hand]));
		pthread_mutex_lock(&(philos->forks_m[philos->r_hand]));
		philos->forks_i[philos->r_hand] = 0;
		pthread_mutex_unlock(&(philos->forks_m[philos->r_hand]));
	}
}
