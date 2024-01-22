/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:06:42 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/19 12:47:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(int ac, char **av, t_gen *inf);

int	main(int ac, char **av)
{
	t_gen	inf;

	if (ac >= 5 && ac <= 6)
		init(ac, av, &inf);
	else
		error(ARG, END);
	return (0);
}

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
