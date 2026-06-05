/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:29:44 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/05 11:02:45 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_data(char *argv[], t_data *data)
{
	data->philo_cnt = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) == 0)
			data->n_must_eat = 0;
		else
			data->n_must_eat = 0;
	}
	else
		data->n_must_eat = 0;
}

void	set_philos(t_philos *philos, t_data data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data.philo_cnt)
	{
		philos[cnt].r_hand = cnt;
		if (cnt == data.philo_cnt - 1)
			philos[cnt].l_hand = 0;
		else
			philos[cnt].l_hand = cnt + 1;
		philos[cnt].time_to_die = data.time_to_die;
		philos[cnt].time_to_eat = data.time_to_eat;
		philos[cnt].time_to_sleep = data.time_to_sleep;
		cnt++;	
	}
}
