/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/29 14:42:04 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_mutex(t_gen *inf);
static void	free_all(t_gen *inf);

int	main(int ac, char **av)
{
	t_gen	inf;
	int		ret_val;

	ret_val = 0;
	if (ac >= 5 && ac <= 6)
		init(ac, av, &inf);
	else
		error(ARG, END);
	init_mutex(&inf);
	if (philo(&inf) == 1)
		ret_val = 1;
	wait_threads(&inf);
	free_all(&inf);
	return (ret_val);
}

static void	free_forks(int i, t_gen *inf);

static void	init_mutex(t_gen *inf)
{
	int	i;

	if (pthread_mutex_init(&inf->mx_print, NULL) != 0)
		return (error(MUTEX_INIT, END));
	if (pthread_mutex_init(&inf->mx_init, NULL) != 0)
		return (pthread_mutex_destroy(&inf->mx_print), error(MUTEX_INIT, END));
	inf->dead.muted = 0;
	if (pthread_mutex_init(&inf->dead.mutex, NULL) != 0)
		return (pthread_mutex_destroy(&inf->mx_print), \
	pthread_mutex_destroy(&inf->mx_init), error(MUTEX_INIT, END));
	inf->forks = malloc(sizeof(t_mutex) * inf->nb_philo);
	if (inf->forks == NULL)
		return (pthread_mutex_destroy(&inf->mx_print), \
	pthread_mutex_destroy(&inf->mx_init), \
	pthread_mutex_destroy(&inf->dead.mutex), error(MALLOC, END));
	i = 0;
	while ((size_t) i < inf->nb_philo)
	{
		inf->forks[i].muted = 0;
		if (pthread_mutex_init(&inf->forks[i].mutex, NULL) != 0)
			free_forks(i, inf);
		i++;
	}
}

static void	free_forks(int i, t_gen *inf)
{
	int	j;

	j = 0;
	while (j < i)
		pthread_mutex_destroy(&inf->forks[j++].mutex);
	free(inf->forks);
	return (pthread_mutex_destroy(&inf->mx_print), \
	pthread_mutex_destroy(&inf->mx_init), \
	pthread_mutex_destroy(&inf->dead.mutex), error(MUTEX_INIT, END));
}

static void	free_all(t_gen *inf)
{
	size_t	j;

	j = 0;
	while (j < inf->nb_philo)
		pthread_mutex_destroy(&inf->forks[j++].mutex);
	free(inf->forks);
	pthread_mutex_destroy(&inf->mx_print);
	pthread_mutex_destroy(&inf->mx_init);
	pthread_mutex_destroy(&inf->dead.mutex);
}
