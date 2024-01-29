/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:32 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/29 14:49:43 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	check_died(t_philo *ph);
// static int	starving(t_philo *ph);

void	*behavior(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->gen->mx_init);
	pthread_mutex_unlock(&ph->gen->mx_init);
	print(THIN, ph);
	if (ph->id % 2 != 0)
		usleep(ph->gen->eat.tv_sec * 1000 + 500);
	print(EATI, ph);
	return (NULL);
}

// static int	check_died(t_philo *ph)
// {
// 	usleep(10 * ph->gen->nb_philo);
// 	pthread_mutex_lock(&ph->gen->dead.mutex);
// 	if (ph->gen->dead.muted != 0)
// 		return (pthread_mutex_unlock(&ph->gen->dead.mutex), 1);
// 	pthread_mutex_unlock(&ph->gen->dead.mutex);
// 	return (0);
// }

// static int	starving(t_philo *ph)
// {
// 	(void) ph;
// 	struct timeval	now;

// 	gettimeofday(&now, NULL);
// 	return (0);
// }
