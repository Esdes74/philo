/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:35:21 by eslamber          #+#    #+#             */
/*   Updated: 2023/11/30 20:07:52 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *ph)
{
	size_t	i;

	i = 0;
	while (i < ph->nb_philo)
		pthread_mutex_destroy(&ph->forks[i++]);
	free(ph->forks);
}
