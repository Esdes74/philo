/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:41:36 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 11:01:55 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static struct timeval	init_time(int ag);
static void	fill_enought(int ac, char **av, t_gen *inf);

void	init(int ac, char **av, t_gen *inf)
{
	int	arg;

	arg = ft_atoi(av[1]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->nb_philo = (size_t) arg;
	if (inf->nb_philo == 0)
		error(ZERO_PHILOS, END);
	arg = ft_atoi(av[2]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->die = init_time(arg);
	arg = ft_atoi(av[3]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->eat = init_time(arg);
	arg = ft_atoi(av[4]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->sleep = init_time(arg);
	fill_enought(ac, av, inf);
}

static struct timeval	init_time(int ag)
{
	struct timeval	res;

	res.tv_sec = ag / 1000;
	res.tv_usec = ag * 1000 % 1000000;
	return (res);
}

static void	fill_enought(int ac, char **av, t_gen *inf)
{
	int	arg;

	inf->stop_enought = 0;
	if (ac == 6)
	{
		arg = ft_atoi(av[5]);
		if (arg < 0)
			error(ARG_NEGATIF, END);
		inf->enought = (size_t) arg;
		inf->stop_enought = 1;
	}
}
