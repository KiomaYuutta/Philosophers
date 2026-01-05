/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:19 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/05 15:01:49 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc)
{
	if (argc < 4 || argc > 5)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	check_chars(char *str)
{
	while (*str)
	{
		if (*str < 48 && *str > 57)
			return (1);
		str++;
	}
	return (0);
}

int	check_values(int argc, char *argv[], t_monitor *monitor)
{
	int	counter;

	counter = 0;
	while (counter <= argc)
	{
		
	}
}
