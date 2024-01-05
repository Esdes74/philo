/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:46:23 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/05 16:01:25 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_unlock_mutex(pthread_t id, t_mod mod, int *dead, t_mutex *mute)
{
	while (mute->val != id && *dead == 0)
	{
		if (mute->val == -1)
		{
			pthread_mutex_lock(mute->mute);
			mute->val = id;
			pthread_mutex_unlock(mute->mute);
		}
	}
}
