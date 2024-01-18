/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:46:23 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/05 19:58:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_unlock_mutex(pthread_t id, t_mod mod, int *dead, t_mutex *mute)
{
	if (mod == PRINT)
	{
		while (mute->val != (char) id && *dead == 0)
		{
			if (mute->val == -1 || (mute->val != -1 && (char) id == -1))
			{
				pthread_mutex_lock(&mute->mute);
				mute->val = (char) id;
				pthread_mutex_unlock(&mute->mute);
			}
		}
	}
	else if (mod == FORKS)
	{
		while (mute->id != id && *dead == 0)
		{
			if (mute->id == 0 || (mute->id != 0 && id == 0))
			{
				pthread_mutex_lock(&mute->mute);
				mute->id = id;
				pthread_mutex_unlock(&mute->mute);
			}
		}
	}
}
