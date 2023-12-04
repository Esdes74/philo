/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:15:25 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 22:47:08 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(t_generals *gn, t_philo *ph);
static void	join_philo(t_generals *gn, t_philo *ph);
static int	check_meal(t_generals *gn, const t_philo *ph);

int	philo(t_generals *gn)
{
	t_philo	*philo;

	philo = (t_philo *) malloc(sizeof(t_philo) * gn->nb_philo);
	if (philo == NULL)
		return (error(MALLOC), 1);
	if (init_philo(gn, philo) == 1)
		return (1);
	while (gn->dead == 0 && check_meal(gn, philo) != 1)
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
	pthread_mutex_lock(&gn->mutex_print);
	ft_printf_fd(2, "start = %d\n", gn->start);
	pthread_mutex_unlock(&gn->mutex_print);
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

static int	check_meal(t_generals *gn, const t_philo *ph)
{
	size_t	i;
	t_time	last_meal;
	t_time	now;

	i = 0;
	while (i < gn->nb_philo)
	{
		now = hour();
		last_meal = now - ph[i].time;
		if (last_meal >= (t_time) gn->time_die \
		&& now - gn->start >= (t_time) gn->time_die)
		{
			print(hour() - gn->start, ph[i], DIED, &gn->mutex_print);
			return (1);
		}
	}
	return (0);
}
