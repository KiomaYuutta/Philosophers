/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 14:44:13 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_monitor *monitor)
{
	int	counter;

	counter = 0;
	while (counter < monitor->philo_cnt)
	{
		monitor[counter].index = counter;
		pthread_create(&(monitor[counter].philos), NULL, &routine, monitor);
		counter++;
	}
	counter = 0;
	while (counter < monitor->philo_cnt)
	{
		pthread_join(monitor[counter].philos, NULL);
		counter++;
	}
	return (0);
}
