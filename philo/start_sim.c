/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/13 16:48:49 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_famine(t_philos *philos, int *finished_eating, int n_philo, int cnt)
{
	pthread_mutex_lock(philos->eaten_lock);
	if (philos[cnt].meny_eaten == philos[cnt].limit)
		(*finished_eating)++;
	if (*finished_eating == n_philo)
	{
		*(philos->leave) = 1;
		pthread_mutex_unlock(philos->eaten_lock);
		return (1);
	}
	pthread_mutex_unlock(philos->eaten_lock);
	return (0);
}

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
	int	finished_eating;

	finished_eating = 0;
	while (1)
	{
		cnt = 0;
		while (cnt < n_philo)
		{
			if ((get_time_ms() - philos[cnt].last_time_eat) > philos[cnt].time_to_die)
			{
				set_death(philos, n_philo);
				log_timestamp(&(philos[cnt]), log_lock, "died", 1);
				return ;
			}
			if (check_famine(philos, &finished_eating, n_philo, cnt))
				return ;
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
