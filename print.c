/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 22:49:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_time h, const t_philo ph, char *mess, pthread_mutex_t *mute)
{
	static int	flag;

	pthread_mutex_lock(mute);
	if (ph.inf->dead == 1 && flag == 1)
	{
		pthread_mutex_unlock(mute);
		return ;
	}
	else if (ft_strncmp(mess, "died", 4) == 0 && flag == 0)
	{
		flag = 1;
		ph.inf->dead = 1;
		ft_printf("%d, %d, %s\n", h, ph.i, mess);
		pthread_mutex_unlock(mute);
		return ;
	}
	ft_printf("%d, %d, %s\n", h, ph.i, mess);
	pthread_mutex_unlock(mute);
}
