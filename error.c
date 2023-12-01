/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:11:46 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 11:37:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(t_error err)
{
	if (err == TOO_MANY_ARG)
		ft_printf_fd(2, "%sError\nThere is too many arguments%s\n", RED, WHITE);
	if (err == NOT_ENOUGH_ARG)
		ft_printf_fd(2, "%sError\nThere is not enough arguments%s\n", RED, WHITE);
	if (err == MALLOC)
		ft_printf_fd(2, "%sError\nProblem with malloc function, abort%s\n", RED, WHITE);
	if (err == MUTEX_INIT)
		ft_printf_fd(2, "%sError\nCan't initialise mutax, abort%s\n", RED, WHITE);
	if (err == CREAT_THREAD)
		ft_printf_fd(2, "%sError\nCan't creat thread, abort%s\n", RED, WHITE);
}
