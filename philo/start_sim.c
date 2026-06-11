/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/11 13:48:49 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_death(t_philos *philos, int n_philos)
{
	int	cnt;

	cnt = 0;
	while (cnt < n_philos)
	{
		philos[cnt].someone_died = 1;
		cnt++;
	}
}

void	monitor(t_philos *philos, pthread_mutex_t *log_lock, int n_philo)
{
	int	cnt;

	while (1)
	{
		cnt = 0;
		while (cnt < n_philo)
		{
			if ((get_time_ms() - philos->last_time_eat) > philos->time_to_die)
			{
				set_death(philos, n_philo);
				log_timestamp(&(philos[cnt]), log_lock, "died", 1);
				return ;
			}
			cnt++;
		}
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
