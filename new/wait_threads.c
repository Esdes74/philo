/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:35:31 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/26 18:21:17 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_gen *inf)
{
	size_t	i;

	i = 0;
	while (i < inf->nb_philo)
	{
		if (inf->tab_philo[i].id_th != 0)
			pthread_join(inf->tab_philo[i].id_th, NULL);
		i++;
	}
}
