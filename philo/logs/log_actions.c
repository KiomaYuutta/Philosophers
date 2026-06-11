/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 14:52:11 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/11 14:02:37 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	log_timestamp(t_philos *philos, pthread_mutex_t *log_lock,
			char *str, int is_monitor)
{
	pthread_mutex_lock(log_lock);
	if (philos->someone_died && !is_monitor)
	{
		pthread_mutex_unlock(log_lock);
		return ;
	}
	ft_putnbr_fd(get_time_ms() - philos->start_time);
	write(1, " philosopher ", ft_strlen(" philosopher "));
	ft_putnbr_fd(philos->philo_id);
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	pthread_mutex_unlock(log_lock);
}
