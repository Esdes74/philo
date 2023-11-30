/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:37:51 by eslamber          #+#    #+#             */
/*   Updated: 2023/11/30 20:08:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include "libft/libft.h"

typedef struct s_philo
{
	int				nb_max_eat;
	size_t			nb_philo;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	pthread_mutex_t	*forks;
}	t_philo;

typedef enum e_error
{
	TOO_MANY_ARG,
	NOT_ENOUGH_ARG,
	MALLOC,
	MUTEX_INIT,
}	t_error;

// Error gestion

void	error(t_error err);

// Free functions

void	free_all(t_philo *ph);

#endif