/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/28 13:17:12 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	enought(t_time h, const t_philo ph, pthread_mutex_t *mute);

void	print(t_time h, const t_philo ph, char *mess, \
pthread_mutex_t *mute)
{
	static int	flag;

	pthread_mutex_lock(mute);
	if (ph.inf->dead == 1 && flag == 1)
	{
		pthread_mutex_unlock(mute);
		return ;
	}
	else if (ft_strncmp(mess, "died", 4) == 0 && flag == 0)
	{
		flag = 1;
		ph.inf->dead = 1;
		ft_printf("%d, %d, %s\n", h, ph.i + 1, mess);
		pthread_mutex_unlock(mute);
		return ;
	}
	else if (ft_strncmp(mess, "enought", 4) == 0 && flag == 0)
	{
		flag = 1;
		return (enought(h, ph, mute));
	}
	ft_printf("%d, %d, %s\n", h, ph.i + 1, mess);
	pthread_mutex_unlock(mute);
}

static void	enought(t_time h, const t_philo ph, pthread_mutex_t *mute)
{
	ph.inf->dead = 1;
	ft_printf("%d, they all eat %d, it's enought\n", h, ph.inf->nb_max_eat);
	pthread_mutex_unlock(mute);
}
