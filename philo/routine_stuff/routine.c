/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:08 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/09 17:34:47 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_spaghetti(t_philos *philos)
{
	grab_forks(philos);
	log_timestamp(philos, "is eating");
	precise_sleep(philos->time_to_eat);
	gettimeofday(philos->last_time_eat, NULL);
	leave_forks(philos);
}

void	tink(t_philos *philos)
{
	log_timestamp(philos, "is thinking");
	precise_sleep(1);
}

void	mimir(t_philos *philos)
{
	log_timestamp(philos, "is sleeping");
	precise_sleep(philos->time_to_sleep);
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
