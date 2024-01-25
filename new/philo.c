/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:47:29 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/25 14:20:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	creat_philo(int i, t_gen *inf, t_philo *ph);

int	philo(t_gen *inf)
{
	int	i;

	inf->tab_philo = malloc(sizeof(t_philo) * inf->nb_philo);
	if (inf->tab_philo == NULL)
		return (error(MALLOC, CONT), 1);
	pthread_mutex_lock(&inf->mx_init);
	i = 0;
	while (i < inf->nb_philo)
	{
		if (creat_philo(i, inf, &inf->tab_philo[i]) == 1)
			return (1);
	}
	pthread_mutex_unlock(&inf->mx_init);
}

static int	creat_philo(int i, t_gen *inf, t_philo *ph)
{
	ph->id = i;
	ph->gen = inf;
	ph->fork = inf->forks[i]
	ph->next_fork = inf->forks[(i + 1) % inf->nb_philo]
	return (error(CREAT_THREAD), 1);
}
