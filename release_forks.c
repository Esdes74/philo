/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:47:55 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/04 15:04:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(size_t i, t_philo *ph, t_generals *gn)
{
	if (ph->right_alloc == 1)
	{
		ph->right_alloc = 0;
		pthread_mutex_unlock(&gn->forks[i]);
	}
	if (ph->left_alloc == 1)
	{
		if (i == 0)
		{
			ph->left_alloc = 0;
			pthread_mutex_unlock(&gn->forks[gn->nb_philo - 1]);
		}
		else
		{
			ph->left_alloc = 0;
			pthread_mutex_unlock(&gn->forks[i - 1]);
		}
	}
}
