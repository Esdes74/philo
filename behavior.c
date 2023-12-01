/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:11:48 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 16:59:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *ph);

void	*behavior(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph;
	philo->time = hour();
	while (philo->inf->ready == -1)
		continue ;
	if (philo->i % 2 == 0 && philo->i != philo->inf->nb_philo - 1)
		eat(philo);
	while (philo->inf->dead == 0)
		eat(philo);
	return (NULL);
}

static void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->forks[ph->i]);
	print(ph->i, hour() - ph->inf->start, FORK, &(ph->inf->mutex_print));
	if (ph->i == 0)
		pthread_mutex_lock(&ph->inf->forks[ph->inf->nb_philo - 1]);
	else
		pthread_mutex_lock(&ph->inf->forks[ph->i - 1]);
	print(ph->i, hour() - ph->inf->start, FORK, &(ph->inf->mutex_print));
	if (hour() - ph->time > ph->inf->time_die)
	{
		ph->inf->dead = 1;
		print(ph->i, hour() - ph->inf->start, DIED, &(ph->inf->mutex_print));
	}
	else
	{
		print(ph->i, hour() - ph->inf->start, EATI, &(ph->inf->mutex_print));
		usleep(ph->inf->time_eat * 1000);
	}
	pthread_mutex_unlock(&ph->inf->forks[ph->i]);
	if (ph->i == 0)
		pthread_mutex_unlock(&ph->inf->forks[ph->inf->nb_philo - 1]);
	else
		pthread_mutex_unlock(&ph->inf->forks[ph->i - 1]);
}
