/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:02:50 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/11 13:56:32 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	size_t	counter;
	int		is_neg;
	int		result;

	counter = 0;
	is_neg = 1;
	result = 0;
	while (nptr[counter] == 32 || (nptr[counter] >= 9 && nptr[counter] <= 13))
		counter++;
	if (nptr[counter] == 45 || nptr[counter] == 43)
	{
		if (nptr[counter] == 45)
			is_neg = -1;
		counter++;
	}
	while (nptr[counter] >= 48 && nptr[counter] <= 57)
	{
		result = result * 10 + (nptr[counter] - 48);
		counter++;
	}
	return (result * is_neg);
}

long long	get_time_ms(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	precise_sleep(int time_ms)
{
	long long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < time_ms)
		usleep(500);
}

void	ft_putnbr_fd(long long n)
{
	char		ln_chr;

	if (n >= 10)
		ft_putnbr_fd(n / 10);
	ln_chr = (n % 10) + 48;
	write(1, &ln_chr, 1);
}

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != 0)
		counter++;
	return (counter);
}
