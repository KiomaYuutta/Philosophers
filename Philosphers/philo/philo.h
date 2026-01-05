/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 03:05:48 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/29 03:05:48 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_monitor
{
	pthread_t	*philos;
	pthread_mutex_t	*forks;
	int			philo_ammount;
	int			ttd;
	int			tte;
	int			tts;
}	t_monitor;

int	main_check(int argc, char *argv[], t_monitor *monitor);

#endif