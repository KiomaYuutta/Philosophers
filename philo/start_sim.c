/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:08:32 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/13 13:51:19 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_simulation(t_philos **philos)
{
	philos++;
	/* int	counter;

	counter = 0;
	while (counter < philos[counter]->philo_cnt)
	{
		philos[counter]->l_hand = counter;
		if (philos[counter + 1] == NULL)
			philos[counter]->r_hand = 0;
		else
			philos[counter]->r_hand = counter + 1;
		pthread_create(&(philos[counter]->philos), NULL, &routine, philos);
		counter++;
	}
	counter = 0;
	while (counter < philos->philo_cnt)
	{
		pthread_join(philos[counter].philos, NULL);
		counter++;
	}
	return (0); */
	return (0);
}
