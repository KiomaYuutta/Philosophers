/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:29:44 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 14:48:37 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "checkers/checks.h"

void	free_mem(void)
{
	
}

void	reset_struct(void)
{
	
}

void	set_vars(char *argv[], t_monitor *monitor)
{
	int	counter;
	int	size;

	counter = 0;
	size = pl_atoi(argv[1]);
	monitor = malloc (sizeof(t_monitor) * size);
	while (counter < size)
	{
		monitor[counter].forks = malloc(sizeof(pthread_mutex_t));
		monitor[counter].philo_cnt = size;
		monitor[counter].ttd = pl_atoi(argv[2]);
		monitor[counter].tte = pl_atoi(argv[3]);
		monitor[counter].tts = pl_atoi(argv[4]);
		pthread_mutex_init((monitor[counter].forks), NULL);
		counter++;
	}
}
