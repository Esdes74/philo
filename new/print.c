/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 11:30:30 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *mess, t_philo *ph)
{
	struct timeval	time;
	struct timeval	print;
	static int		printed;

	gettimeofday(&time, NULL);
	print.tv_usec = (1000000 + time.tv_usec - ph->gen->start.tv_usec) % 1000000;
	print.tv_sec = time.tv_sec - ph->gen->start.tv_sec - (time.tv_usec < \
	ph->gen->start.tv_usec);
	pthread_mutex_lock(&ph->gen->dead.mutex);
	if (ft_strncmp(mess, ENOU, ft_strlen(mess)) == 0 && printed == 0)
	{
		pthread_mutex_lock(&ph->gen->mx_print);
		printf("%lu%03ld %s\n", print.tv_sec, print.tv_usec / 1000, mess);
		pthread_mutex_unlock(&ph->gen->mx_print);
		printed++;
	}
	if (ph->gen->dead.muted == 0)
	{
		pthread_mutex_lock(&ph->gen->mx_print);
		printf("%lu%03ld %4ld %s\n", print.tv_sec, print.tv_usec / 1000, \
	ph->id, mess);
		pthread_mutex_unlock(&ph->gen->mx_print);
	}
	pthread_mutex_unlock(&ph->gen->dead.mutex);
}
