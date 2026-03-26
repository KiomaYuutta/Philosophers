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

typedef struct s_philos
{
	pthread_mutex_t	*forks;
	pthread_t		philos;
	int			l_hand;
	int			r_hand;
	int				philo_cnt;
	int				ttd;
	int				tte;
	int				tts;
}	t_philos;

void	*routine(void *arg);
void	reset_struct(void);
void	set_vars(char *argv[], t_philos **philos);
void	free_mem(void);
int		main_check(int argc, char *argv[]);
int		start_simulation(t_philos **philos);

#endif