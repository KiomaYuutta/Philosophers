/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:40:19 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/11 20:58:52 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc)
{
	if (argc != 1 && (argc < 4 || argc > 5))
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	return (0);
}

int	check_values2(int counter, char *argv[])
{
	if (counter == 1 && pl_atoi(argv[counter]) > 200)
	{
		printf("Can't run with more than 200 philosophers\n");
		return (1);
	}
	if (counter > 1 && counter < 5 && pl_atoi(argv[counter]) < 60)
	{
		printf("Miliseconds time need to be at least 60ms\n");
		return (1);
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
		if (pl_atoi(argv[counter]) == 0)
		{
			printf("No value should be 0\n");
			return (1);
		}
		if (check_values2(counter, argv))
			return (1);
		counter++;
	}
	return (0);
}
