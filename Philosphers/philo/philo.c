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

int	main(int argc, char *argv[])
{
	t_monitor	*monitor;

	monitor = NULL;
	if (main_check(argc, argv))
	{
		return (1);
	}
	set_vars(argv, monitor);
	start_simulation(monitor);
	return (0);
}
