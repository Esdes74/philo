/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:47:29 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/28 13:43:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	creat_philo(int i, t_gen *inf, t_philo *ph);

int	philo(t_gen *inf)
{
	size_t	i;

	inf->tab_philo = malloc(sizeof(t_philo) * inf->nb_philo);
	if (inf->tab_philo == NULL)
		return (error(MALLOC, CONT), 1);
	inf->stop = 0;
	inf->died = 0;
	pthread_mutex_lock(&inf->mx_init);
	i = 0;
	while (i < inf->nb_philo)
	{
		if (creat_philo(i, inf, &inf->tab_philo[i]) == 1)
			return (1);
		i++;
	}
	gettimeofday(&inf->start, NULL);
	pthread_mutex_unlock(&inf->mx_init);
	return (0);
}

static int	creat_philo(int i, t_gen *inf, t_philo *ph)
{
	ph->id = i + 1;
	ph->gen = inf;
	ph->fork = &inf->forks[i];
	ph->next_fork = &inf->forks[(i + 1) % inf->nb_philo];
	if (pthread_create(&ph->id_th, NULL, behavior, ph) != 0)
		return (error(CREAT_THREAD, CONT), 1);
	return (0);
}
