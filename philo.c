/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:15:25 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 15:57:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_generals *gn, t_philo *ph);
static void	join_philo(t_generals *gn, t_philo *ph);

int	philo(t_generals *gn)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo) * gn->nb_philo);
	if (philo == NULL)
		return (error(MALLOC), 1);
	if (init_philo(gn, philo) == 1)
		return (1);
	while (gn->dead == 0)
		continue ;
	join_philo(gn, philo);
	return (free(philo), 0);
}

static int	init_philo(t_generals *gn, t_philo *ph)
{
	size_t	i;

	i = 0;
	while (i < gn->nb_philo)
	{
		ph[i].inf = gn;
		ph[i].i = i;
		if (pthread_create(&ph[i].id, NULL, behavior, &ph[i]) != 0)
		{
			error(CREAT_THREAD);
			break ;
		}
		i++;
	}
	gn->start = hour();
	if (i == gn->nb_philo)
		gn->ready = 1;
	else
	{
		gn->err_thread = i;
		gn->ready = 0;
	}
	return (0);
}

static void	join_philo(t_generals *gn, t_philo *ph)
{
	size_t	i;

	i = 0;
	if (gn->err_thread == 0)
		while (i < gn->nb_philo)
			pthread_join(ph[i++].id, NULL);
	else
		while (i < gn->err_thread)
			pthread_join(ph[i++].id, NULL);
}
