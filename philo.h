/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:37:51 by eslamber          #+#    #+#             */
/*   Updated: 2023/12/04 15:46:29 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

# define RED "\033[91m"
# define WHITE "\033[0m"
# define FORK "has taken a fork"
# define EATI "is eating"
# define SLEE "is sleeping"
# define THIN "is thinking"
# define DIED "died"

typedef long int	t_time;

typedef struct s_generals
{
	int				ready;
	int				nb_max_eat;
	int				dead;
	int				err_thread;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*forks;
	t_time			start;
}	t_generals;

typedef struct s_philo
{
	int			right_alloc;
	int			left_alloc;
	int			iter;
	int			i;
	pthread_t	id;
	t_time		time;
	t_generals	*inf;
}	t_philo;

typedef enum e_error
{
	TOO_MANY_ARG,
	NOT_ENOUGH_ARG,
	MALLOC,
	MUTEX_INIT,
	CREAT_THREAD,
	WRONG_ARGS,
}	t_error;

// Philos gestion

int			philo(t_generals *gn);

void		*behavior(void *ph);

long int	hour(void);

void		print(t_time h, const t_philo ph, char *mess, \
pthread_mutex_t *mute);

// Error gestion

void		error(t_error err);

// Free functions

void		free_all(t_generals *ph);

void		release_forks(size_t i, t_philo *ph, t_generals *gn);

#endif