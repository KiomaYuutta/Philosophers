/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/14 15:05:32 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_famine(t_philos *philos, int *finished_eating, int n_philo, int cnt)
{
	pthread_mutex_lock(philos->end_lock);
	if (philos[cnt].meny_eaten >= philos[cnt].limit)
		(*finished_eating)++;
	if (*finished_eating == n_philo)
	{
		*(philos->leave) = 1;
		pthread_mutex_unlock(philos->end_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->end_lock);
	return (0);
}

void	monitor(t_philos *philos, pthread_mutex_t *log_lock, int n_philo)
{
	int	cnt;
	int	finished_eating;

	while (1)
	{
		cnt = -1;
		finished_eating = 0;
		while (++cnt < n_philo)
		{
			pthread_mutex_lock(philos->end_lock);
			if ((get_time_ms() - philos[cnt].last_time_eat)
				> philos[cnt].time_to_die)
			{
				*(philos->someone_died) = 1;
				pthread_mutex_unlock(philos->end_lock);
				usleep(1000);
				log_timestamp(&(philos[cnt]), log_lock, "died", 1);
				return ;
			}
			pthread_mutex_unlock(philos->end_lock);
			if (check_famine(philos, &finished_eating, n_philo, cnt))
				return ;
		}
		usleep(250);
	}
}

int	start_simulation(t_philos *philos, pthread_mutex_t *log_lock, int n_philo)
{
	int	cnt;

	cnt = 0;
	while (cnt < n_philo)
	{
		pthread_create(&(philos[cnt].philos), 0, &routine, &(philos[cnt]));
		cnt++;
	}
	cnt = 0;
	monitor(philos, log_lock, n_philo);
	while (cnt < n_philo)
		pthread_join(philos[cnt++].philos, NULL);
	return (0);
}
