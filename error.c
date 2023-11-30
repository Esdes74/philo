/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:46 by eslamber          #+#    #+#             */
/*   Updated: 2023/11/30 19:35:11 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(t_error err)
{
	if (err == TOO_MANY_ARG)
		ft_printf_fd(2, "Error\nThere is too many arguments\n");
	if (err == NOT_ENOUGH_ARG)
		ft_printf_fd(2, "Error\nThere is not enough arguments\n");
	if (err == MALLOC)
		ft_printf_fd(2, "Error\nProblem with malloc function\n");
	if (err == MUTEX_INIT)
		ft_printf_fd(2, "Error\nProblem whith initialisation of mutex\n");
}
