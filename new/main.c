/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/25 14:01:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init(int ac, char **av, t_gen *inf);
static void	init_mutex(t_gen *inf);
static void	free_all(t_gen *inf);

int	main(int ac, char **av)
{
	t_gen	inf;

	if (ac >= 5 && ac <= 6)
		init(ac, av, &inf);
	else
		error(ARG, END);
	init_mutex(&inf);
	if (init_philo(&inf) == 1)
		return (free_all(&inf), 1);
	free_all(&inf);
	return (0);
}

static void	init(int ac, char **av, t_gen *inf)
{
	int	arg;

	arg = ft_atoi(av[1]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->nb_philo = (size_t) arg;
	arg = ft_atoi(av[2]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->die = (size_t) arg;
	arg = ft_atoi(av[3]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->eat = (size_t) arg;
	arg = ft_atoi(av[4]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->sleep = (size_t) arg;
	if (ac == 6)
	{
		arg = ft_atoi(av[5]);
		if (arg < 0)
			error(ARG_NEGATIF, END);
		inf->nb_eat = (size_t) arg;
	}
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
	int	j;

	j = 0;
	while (j < inf->nb_philo)
		pthread_mutex_destroy(&inf->forks[j++].mutex);
	free(inf->forks);
	pthread_mutex_destroy(&inf->mx_print);
	pthread_mutex_destroy(&inf->mx_init);
	pthread_mutex_destroy(&inf->dead.mutex);
}