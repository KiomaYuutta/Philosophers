/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:50:06 by dide-alm          #+#    #+#             */
/*   Updated: 2026/01/08 12:56:09 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "../philo.h"

int	pl_atoi(char *number);
int	check_args(int argc);
int	check_values(int argc, char *argv[]);

#endif