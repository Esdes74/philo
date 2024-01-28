/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:48:15 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/28 14:35:01 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *mess, t_philo *ph)
{
	struct timeval	time;
	struct timeval	print;

	gettimeofday(&time, NULL);
	print.tv_usec = (1000000 + time.tv_usec - ph->gen->start.tv_usec) % 1000000;
	print.tv_sec = time.tv_sec - ph->gen->start.tv_sec - (time.tv_usec < \
	ph->gen->start.tv_usec);
	pthread_mutex_lock(&ph->gen->mx_print);
	if (ph->gen->stop == 0)
		printf("%lu%03ld %4ld %s\n", print.tv_sec, print.tv_usec / 1000, \
	ph->id, mess);
	pthread_mutex_unlock(&ph->gen->mx_print);
}
