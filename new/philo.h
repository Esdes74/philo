/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:07:12 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/25 14:02:03 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H



# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct s_mutex
{
	int				muted;
	pthread_mutex_t	mutex;
}	t_mutex;

typedef struct s_gen
{
	size_t			nb_philo;
	size_t			die;
	size_t			eat;
	size_t			sleep;
	size_t			nb_eat;
	t_mutex			dead;
	t_mutex			*forks;
	pthread_mutex_t	mx_print;
	pthread_mutex_t	mx_init;
	t_philo			*tab_philo;
}	t_gen;

typedef struct s_philo
{
	size_t	id;
	t_mutex	*fork;
	t_mutex	*next_fork;
	t_gen	*gen;
}	t_philo;

enum	e_err
{
	ARG,
	ARG_NEGATIF,
	MUTEX_INIT,
	MALLOC
};

enum	e_err_type
{
	CONT,
	END
};

void	error(enum e_err err, enum e_err_type type);

int		philo(t_gen *inf);

#endif
