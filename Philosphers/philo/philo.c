/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 03:10:08 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/29 03:10:08 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset_struct(t_monitor *monitor)
{
	monitor->forks = NULL;
	monitor->philo_ammount = 0;
	monitor->philos = NULL;
	monitor->ttd = 0;
	monitor->tte = 0;
	monitor->tts = 0;
}

int	main(int argc, char *argv[])
{
	t_monitor	monitor;

	reset_struct(&monitor);
	if (main_check(argc, argv, &monitor))
	{
		return (1);
	}
	return (0);
}
