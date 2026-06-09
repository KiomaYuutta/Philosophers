/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/09 18:05:48 by dide-alm         ###   ########.fr       */
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

void	monitor(t_philos *philos, int n_philo)
{
	int	cnt;

	while (1)
	{
		cnt = 0;
		while (cnt < n_philo)
		{
			if ((get_time_ms() - philos->last_time_eat) < philos->time_to_die)
			{
				set_death(philos, n_philo);
				log_timestamp(&(philos[cnt]), "died");
				return ;
			}
			cnt++;
		}
	}
}

int	start_simulation(t_philos *philos, int n_philo)
{
	int	cnt;

	cnt = 0;
	while (cnt < n_philo)
	{
		philos->start_time = get_time_ms();
		philos->last_time_eat = philos->start_time;
		philos->log_time = philos->start_time;
		pthread_create(&(philos[cnt].philos), 0, &routine, &(philos[cnt]));
		cnt++;
	}
	cnt = 0;
	monitor(philos, n_philo);
	while (cnt < n_philo)
		pthread_join(philos[cnt++].philos, NULL);
	return (0);
}
