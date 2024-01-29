/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:30:58 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/29 14:39:22 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	compare_time(struct timeval t1, struct timeval t2)
{
	if (t1.tv_sec != t2.tv_sec)
		return (t2.tv_sec - t1.tv_sec);
	return (t2.tv_usec - t1.tv_usec);
}
