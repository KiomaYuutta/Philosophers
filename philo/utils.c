/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:02:50 by dide-alm          #+#    #+#             */
/*   Updated: 2026/06/03 11:03:01 by dide-alm         ###   ########.fr       */
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