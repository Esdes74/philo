/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:23:36 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 10:24:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(enum e_err err, enum e_err_type type)
{
	if (err == ARG)
	{
		ft_printf_fd(2, "Error : There is a problem with arguments.\n");
		ft_printf_fd(2, "Try with \"./philo nb_philo time_to_die time_to_eat \
time_to_sleep nb_must_eat(optional)\".\n");
	}
	else if (err == ARG_NEGATIF)
		ft_printf_fd(2, "Error : Arguments must be positifs\n");
	else if (err == ZERO_PHILOS)
		ft_printf_fd(2, "Error : Must have 1 philo minimum\n");
	else if (err == MUTEX_INIT)
		ft_printf_fd(2, "Error : Problem with initialisation of mutex\n");
	else if (err == MALLOC)
		ft_printf_fd(2, "Error : Problem with malloc allocation\n");
	else if (err == CREAT_THREAD)
		ft_printf_fd(2, "Error : Problem with thread creation\n");
	if (type == END)
		exit(1);
}
