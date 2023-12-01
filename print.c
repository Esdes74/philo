/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 17:01:20 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(size_t id, t_time h, char *mess, pthread_mutex_t *mute)
{
	pthread_mutex_lock(mute);
	ft_printf("%d, %d, %s\n", h, id, mess);
	pthread_mutex_unlock(mute);
}
