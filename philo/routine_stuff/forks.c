/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:44:22 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/09 14:00:06 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	grab_fork_right(t_philos *philos)
{
	while (1)
	{
		if (philos->someone_died)
		return ;
		pthread_mutex_lock(&(philos->forks_m[philos->r_hand]));
		if (!(philos->forks_i[philos->r_hand]))
		{
			philos->forks_i[philos->r_hand] = 1;
		}
	}
}

void	grab_fork_left(t_philos *philos)
{
	
}

void	grab_forks(t_philos *philos)
{
	if (philos->someone_died)
		return ;
	if (philos->philo_id % 2 == 0)
	{
		grab_fork_right(philos);
		grab_fork_left(philos);
	}
	else
	{
		grab_fork_left(philos);
		grab_fork_right(philos);
	}
}
