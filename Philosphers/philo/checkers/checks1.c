/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:19 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 12:55:59 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include "checks.h"

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

int	check_values(int argc, char *argv[])
{
	int	counter;

	counter = 1;
	while (counter <= argc)
	{
		if (check_chars(argv[counter]))
		{
			printf("Invalid characters in arguments\n");
			return (1);
		}
		if (pl_atoi(argv[counter]) == -1)
		{
			printf("Number given is bigger than MAX_INT\n");
			return (1);
		}
		counter++;
	}
	return (0);
}
