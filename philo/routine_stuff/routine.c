/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:08 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/05 22:53:26 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_spaghetti(t_philos *philos)
{
	grab_forks(philos);
	log(philos->philo_id, "is eating");
	usleep(philos->time_to_eat);
	philos->last_time_eat = get_current_time();
	if (philos->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(&(philos->forks[philos->r_hand]));
		pthread_mutex_unlock(&(philos->forks[philos->l_hand]));
	}
	else
	{
		pthread_mutex_unlock(&(philos->forks[philos->l_hand]));
		pthread_mutex_unlock(&(philos->forks[philos->r_hand]));
	}
}

void	tink(t_philos *philos)
{
	log(philos->philo_id, "is thinking");
	usleep(1);
}

void	mimir(t_philos *philos)
{
	log(philos->philo_id, "is sleeping");
	usleep(philos->time_to_sleep);
}

void	*routine(void *arg)
{
	t_philos	*philos;
	int			cnt;

	philos = arg;
	cnt = 0;
	if (philos->limit == 0)
		cnt--;
	while (cnt != philos->limit)
	{
		eat_spaghetti(philos);
		tink(philos);
		mimir(philos);
		if (philos->limit != 0)
			cnt++;
	}
	return (NULL);
}
