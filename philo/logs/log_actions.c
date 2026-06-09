/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:11 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/09 17:46:33 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	log_timestamp(t_philos *philos, char *str)
{
	pthread_mutex_lock(philos->log_lock);
	printf("%lld philo %d %s", calculate_time(philos->start_time, philos->log_time),
		philos->philo_id, str);
	pthread_mutex_unlock(philos->log_lock);
}