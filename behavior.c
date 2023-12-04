/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:11:48 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/04 15:04:45 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *ph);
static void	philo_init(t_philo *ph);
static void	alloc_forks(t_philo *ph);

void	*behavior(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *) ph;
	philo_init(philo);
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
	alloc_forks(ph);
	print(hour() - ph->inf->start, *ph, EATI, &(ph->inf->mutex_print));
	ph->time = hour();
	usleep(ph->inf->time_eat * 1000);
	ph->iter = ph->iter + 1;
	release_forks(ph->i, ph, ph->inf);
}

static void	philo_init(t_philo *ph)
{
	ph->time = ph->inf->start;
	ph->iter = 0;
	ph->right_alloc = 0;
	ph->left_alloc = 0;
}

static void	alloc_forks(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->forks[ph->i]);
	print(hour() - ph->inf->start, *ph, FORK, &(ph->inf->mutex_print));
	ph->right_alloc = 1;
	if (ph->i == 0)
	{
		ph->left_alloc = 1;
		pthread_mutex_lock(&ph->inf->forks[ph->inf->nb_philo - 1]);
	}
	else
	{
		ph->left_alloc = 1;
		pthread_mutex_lock(&ph->inf->forks[ph->i - 1]);
	}
	print(hour() - ph->inf->start, *ph, FORK, &(ph->inf->mutex_print));
}
