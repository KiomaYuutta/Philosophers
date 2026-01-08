/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:36:51 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 14:02:57 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checks.h"

int	main_check(int argc, char *argv[])
{
	if (check_args(argc - 1))
		return (1);
	if (check_values(argc - 1, argv))
		return (1);
	return (0);
}
