/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:11 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/10 18:42:08 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	log_timestamp(t_philos *philos, pthread_mutex_t *log_lock, char *str)
{
	pthread_mutex_lock(log_lock);
	if (philos->someone_died)
	{
		pthread_mutex_unlock(log_lock);
		return ;
	}
	printf("%lld philo %d %s\n", get_time_ms() - philos->start_time, philos->philo_id, str);
	pthread_mutex_unlock(log_lock);
}