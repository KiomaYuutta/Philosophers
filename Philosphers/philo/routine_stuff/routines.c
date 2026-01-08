/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:14:08 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 14:02:01 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_spaghetti(t_monitor *monitor)
{
	monitor->ttd = monitor->ttd;
	monitor->tte = monitor->tte;
	monitor->tts = monitor->tts;
}

void	*routine(void *arg)
{
	t_monitor *monitor;

	monitor = arg;
	usleep(50);
	usleep(monitor->tts);

	eat_spaghetti(monitor);
	return (NULL);
}
