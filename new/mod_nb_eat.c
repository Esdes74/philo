/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_nb_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:55:46 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 11:56:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mod_nb_eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->nb_eat.mutex);
	ph->nb_eat.muted++;
	pthread_mutex_unlock(&ph->nb_eat.mutex);
}
