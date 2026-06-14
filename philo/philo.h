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
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_data
{
	pthread_mutex_t	*log_lock;
	int				philo_cnt;
	int				n_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_data;

typedef struct s_philos
{
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	*log_lock;
	pthread_mutex_t	*end_lock;
	pthread_t		philos;
	long long		start_time;
	long long		last_time_eat;
	int				*forks_i;
	int				*leave;
	int				philo_id;
	int				l_hand;
	int				r_hand;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				limit;
	int				someone_died;
	int				meny_eaten;
}	t_philos;

long long	get_time_ms(void);
void		ft_putnbr_fd(long long n);
void		*routine(void *arg);
void		reset_struct(void);
void		log_timestamp(t_philos *philos, pthread_mutex_t *log_lock,
				char *str, int is_monitor);
void		set_data(char *argv[], t_data *data);
void		set_philos(t_philos *philos, t_data data,
				pthread_mutex_t *mutex);
void		leave_forks(t_philos *philos);
void		grab_forks(t_philos *philos);
void		precise_sleep(int time_ms);
void		free_mem(void);
int			ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
int			main_check(int argc, char *argv[]);
int			start_simulation(t_philos *philos, pthread_mutex_t *log_lock,
				int n_philo);
int			pl_atoi(char *number);
int			check_args(int argc);
int			check_values(int argc, char *argv[]);
int			check_chars(char *str);
int			clean_memory(t_philos *philos, pthread_mutex_t *mutex,
				int n_philos);

#endif