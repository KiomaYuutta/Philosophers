/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:45:43 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/03 10:30:05 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	pl_atoi(char *number)
{
	int	result;
	int	counter;

	result = 0;
	counter = 0;
	while (*number != 0)
	{
		result = (result * 10) + (*number - 48);
		if (result != 0)
			counter++;
		if (counter == 11)
			return (-1);
		number++;
	}
	return (result);
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
