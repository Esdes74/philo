/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:32 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/28 14:35:42 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*behavior(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->gen->mx_init);
	pthread_mutex_unlock(&ph->gen->mx_init);
	print(THIN, ph);
	if (ph->id % 2 != 0)
		usleep(ph->gen->eat * 1000);
	print(EATI, ph);
	return (NULL);
}
