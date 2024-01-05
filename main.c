/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:38:19 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/05 19:09:28 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo(char **av, t_generals *ph);
static int	check_arg(char *av, t_generals *ph);
static int	init_mutex(t_generals *ph);

int	main(int ac, char **av)
{
	t_generals	ph;

	if (ac < 5)
		return (error(NOT_ENOUGH_ARG), 1);
	else if (ac > 6)
		return (error(TOO_MANY_ARG), 1);
	if (init_philo(av, &ph) == 1)
		return (1);
	if (init_mutex(&ph) == 1)
		return (1);
	if (philo(&ph) == 1)
		return (1);
	return (free_all(&ph), 0);
}

static int	init_philo(char **av, t_generals *ph)
{
	ph->ready = -1;
	ph->start = 0;
	ph->dead = 0;
	ph->err_thread = 0;
	ph->nb_philo = ft_atoi(av[1]);
	ph->time_die = ft_atoi(av[2]);
	ph->time_eat = ft_atoi(av[3]);
	ph->time_sleep = ft_atoi(av[4]);
	ph->forks = 0;
	ph->mutex_print.val = -1;
	ph->mutex_print.id = 0;
	if (av[5] != NULL)
		ph->nb_max_eat = ft_atoi(av[5]);
	else
		ph->nb_max_eat = -1;
	if (check_arg(av[5], ph) == 1)
		return (1);
	ph->forks = (t_mutex *) malloc(sizeof(t_mutex) * \
	(ph->nb_philo + 1));
	if (ph->forks == NULL)
		return (error(MALLOC), 1);
	return (0);
}

static int	init_mutex(t_generals *ph)
{
	int	i;
	int	j;

	i = 0;
	if (pthread_mutex_init(&ph->mutex_print.mute, NULL) != 0)
		return (error(MUTEX_INIT), free(ph->forks), 1);
	while (i < ph->nb_philo)
	{
		ph->forks[i].val = -1;
		ph->forks[i].id = 0;
		if (pthread_mutex_init(&ph->forks[i++].mute, NULL) != 0)
		{
			error(MUTEX_INIT);
			break ;
		}
	}
	j = 0;
	if (i != ph->nb_philo)
	{
		while (j < i && i != ph->nb_philo)
			pthread_mutex_destroy(&ph->forks[j++].mute);
		return (pthread_mutex_destroy(&ph->mutex_print.mute), free(ph->forks), \
				1);
	}
	return (0);
}

static int	check_arg(char *av, t_generals *ph)
{
	if (ph->nb_philo < 0 || ph->time_die < 0 || ph->time_eat < 0 \
	|| ph->time_sleep < 0)
		return (error(WRONG_ARGS), 1);
	else if (av != NULL && ph->nb_max_eat < 0)
		return (error(WRONG_ARGS), 1);
	return (0);
}
