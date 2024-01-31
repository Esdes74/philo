/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:26:44 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 11:20:02 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	taking_forks(t_philo *ph);
static void	release_forks(t_philo *ph);
static int	check_died(t_philo *ph);
static int	starving(t_philo *ph);

int	eating(t_philo *ph)
{
	struct timeval	now;
	struct timeval	waited;
	struct timeval	comp;

	if (taking_forks(ph) != 0)
		return (1);
	print(EATI, ph);
	pthread_mutex_lock(&ph->nb_eat.mutex);
	ph->nb_eat.muted++;
	pthread_mutex_unlock(&ph->nb_eat.mutex);
	gettimeofday(&ph->gen->die, NULL);
	gettimeofday(&now, NULL);
	gettimeofday(&waited, NULL);
	comp.tv_usec = (1000000 + waited.tv_usec - now.tv_usec) % 1000000;
	comp.tv_sec = waited.tv_sec - now.tv_sec - \
	(waited.tv_usec < now.tv_usec);
	while (check_died(ph) == 0 && compare_time(ph->gen->sleep, comp) < 0)
	{
		starving(ph);
		usleep(100);
		starving(ph);
		gettimeofday(&waited, NULL);
		comp.tv_usec = (1000000 + waited.tv_usec - now.tv_usec) % 1000000;
		comp.tv_sec = waited.tv_sec - now.tv_sec - \
		(waited.tv_usec < now.tv_usec);
	}
	return (release_forks(ph), 0);
}

static int	taking_forks(t_philo *ph)
{
	int	flag;

	flag = 2;
	pthread_mutex_lock(&ph->fork->mutex);
	if (ph->fork->muted == 0)
	{
		ph->fork->muted = ph->id;
		print(FORK, ph);
	}
	if ((size_t) ph->fork->muted == ph->id)
		flag--;
	pthread_mutex_unlock(&ph->fork->mutex);
	pthread_mutex_lock(&ph->next_fork->mutex);
	if (ph->next_fork->muted == 0)
	{
		ph->next_fork->muted = ph->id;
		print(FORK, ph);
	}
	if ((size_t) ph->next_fork->muted == ph->id)
		flag--;
	pthread_mutex_unlock(&ph->next_fork->mutex);
	return (flag);
}

static void	release_forks(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork->mutex);
	ph->fork->muted = 0;
	pthread_mutex_unlock(&ph->fork->mutex);
	pthread_mutex_lock(&ph->next_fork->mutex);
	ph->next_fork->muted = 0;
	pthread_mutex_unlock(&ph->next_fork->mutex);
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
