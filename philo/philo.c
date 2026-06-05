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
	t_philos	*philos;
	t_data		data;

	philos = NULL;
	if (main_check(argc, argv))
		return (1);
	set_data(argv, &data);
	philos = malloc(data.philo_cnt * sizeof(t_philos));
	if (!philos)
		return (1);
	set_philos(philos, data);
	start_simulation(philos);
	return (0);
}
