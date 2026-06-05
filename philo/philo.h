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

typedef struct s_data
{
	int	philo_cnt;
	int	n_must_eat;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_data;

typedef struct s_philos
{
	pthread_mutex_t	*forks;
	pthread_t		philos;
	int			l_hand;
	int			r_hand;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
}	t_philos;

void	*routine(void *arg);
void	reset_struct(void);
void	set_data(char *argv[], t_data *data);
void	set_philos(t_philos *philos, t_data data);
void	free_mem(void);
int		ft_atoi(const char *nptr);
int		main_check(int argc, char *argv[]);
int		start_simulation(t_philos *philos);
int		pl_atoi(char *number);
int		check_args(int argc);
int		check_values(int argc, char *argv[]);
int		check_chars(char *str);

#endif