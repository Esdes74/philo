/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:41:36 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/29 14:48:15 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static struct timeval	init_time(int ag);

void	init(int ac, char **av, t_gen *inf)
{
	int	arg;

	arg = ft_atoi(av[1]);
	if (arg < 0)
		error(ARG_NEGATIF, END);
	inf->nb_philo = (size_t) arg;
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
	if (ac == 6)
	{
		arg = ft_atoi(av[5]);
		if (arg < 0)
			error(ARG_NEGATIF, END);
		inf->nb_eat = (size_t) arg;
	}
}

static struct timeval	init_time(int ag)
{
	struct timeval	res;

	res.tv_sec = ag / 1000;
	res.tv_usec = ag * 1000 % 1000000;
	return (res);
}
