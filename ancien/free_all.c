/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:35:21 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/05 15:08:56 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_generals *ph)
{
	int	i;

	i = 0;
	while (i < ph->nb_philo)
		pthread_mutex_destroy(&ph->forks[i++].mute);
	free(ph->forks);
	pthread_mutex_destroy(&ph->mutex_print.mute);
}
