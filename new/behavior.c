/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:31:32 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/29 19:14:59 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_died(t_philo *ph);
static int	starving(t_philo *ph);
static void	sleeping(t_philo *ph);
static void	thinking(t_philo *ph);

void	*behavior(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *) philo;
	pthread_mutex_lock(&ph->gen->mx_init);
	gettimeofday(&ph->eat, NULL);
	pthread_mutex_unlock(&ph->gen->mx_init);
	print(THIN, ph);
	if (ph->id % 2 != 0)
		usleep(ph->gen->eat.tv_sec * 1000000 + ph->gen->eat.tv_usec + 500);
	while (check_died(ph) == 0)
	{
		while (check_died(ph) == 0 && eating(ph) == 1)
			starving(ph);
		sleeping(ph);
		starving(ph);
		thinking(ph);
		starving(ph);
	}
	return (NULL);
}

static void	sleeping(t_philo *ph)
{
	print(SLEE, ph);
	usleep(ph->gen->sleep.tv_sec * 1000000 + ph->gen->sleep.tv_usec);
}

static void	thinking(t_philo *ph)
{
	print(THIN, ph);
}

static int	check_died(t_philo *ph)
{
	usleep(10 * ph->gen->nb_philo);
	pthread_mutex_lock(&ph->gen->dead.mutex);
	if (ph->gen->dead.muted != 0)
		return (pthread_mutex_unlock(&ph->gen->dead.mutex), 1);
	pthread_mutex_unlock(&ph->gen->dead.mutex);
	return (0);
}

static int	starving(t_philo *ph)
{
	struct timeval	now;
	struct timeval	comp;

	gettimeofday(&now, NULL);
	comp.tv_usec = (1000000 + now.tv_usec - ph->eat.tv_usec) % 1000000;
	comp.tv_sec = now.tv_sec - ph->eat.tv_sec - \
	(now.tv_usec < ph->eat.tv_usec);
	if (compare_time(ph->gen->die, comp) > 0)
	{
		print(DIED, ph);
		pthread_mutex_lock(&ph->gen->dead.mutex);
		ph->gen->dead.muted = 1;
		pthread_mutex_unlock(&ph->gen->dead.mutex);
	}
	return (0);
}
