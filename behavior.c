/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:11:48 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 22:42:23 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *ph);

void	*behavior(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph;
	philo->time = philo->inf->start;
	while (philo->inf->ready == -1)
		continue ;
	if (philo->i % 2 == 1)
		usleep(philo->inf->time_eat * 1000);
	while (philo->inf->dead == 0)
	{
		eat(philo);
		print(hour() - philo->inf->start, *philo, SLEE, \
		&philo->inf->mutex_print);
		usleep(philo->inf->time_sleep * 1000);
		print(hour() - philo->inf->start, *philo, THIN, \
		&philo->inf->mutex_print);
	}
	return (NULL);
}

static void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->forks[ph->i]);
	print(hour() - ph->inf->start, *ph, FORK, &(ph->inf->mutex_print));
	if (ph->i == 0)
		pthread_mutex_lock(&ph->inf->forks[ph->inf->nb_philo - 1]);
	else
		pthread_mutex_lock(&ph->inf->forks[ph->i - 1]);
	print(hour() - ph->inf->start, *ph, FORK, &(ph->inf->mutex_print));
	print(hour() - ph->inf->start, *ph, EATI, &(ph->inf->mutex_print));
	ph->time = hour();
	usleep(ph->inf->time_eat * 1000);
	pthread_mutex_unlock(&ph->inf->forks[ph->i]);
	if (ph->i == 0)
		pthread_mutex_unlock(&ph->inf->forks[ph->inf->nb_philo - 1]);
	else
		pthread_mutex_unlock(&ph->inf->forks[ph->i - 1]);
}
