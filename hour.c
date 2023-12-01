/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hour.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:17 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/01 15:47:16 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	hour(void)
{
	struct timeval	day;

	gettimeofday(&day, NULL);
	return ((day.tv_sec * 1000) + (day.tv_usec / 1000));
}
