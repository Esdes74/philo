/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:07:12 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/31 11:08:33 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include "libft/libft.h"

# define FORK "has taken a fork"
# define EATI "is eating"
# define SLEE "is sleeping"
# define THIN "is thinking"
# define DIED "died"
# define ENOU "they have enought eaten"

typedef struct s_mutex
{
	int				muted;
	pthread_mutex_t	mutex;
}	t_mutex;

typedef struct s_gen
{
	int				stop_enought;
	size_t			nb_philo;
	size_t			enought;
	t_mutex			dead;
	t_mutex			*forks;
	pthread_mutex_t	mx_print;
	pthread_mutex_t	mx_init;
	struct timeval	die;
	struct timeval	eat;
	struct timeval	sleep;
	struct timeval	start;
	struct s_philo	*tab_philo;
}	t_gen;

typedef struct s_philo
{
	size_t			id;
	pthread_t		id_th;
	struct timeval	eat;
	t_mutex			nb_eat;
	t_mutex			*fork;
	t_mutex			*next_fork;
	t_gen			*gen;
}	t_philo;

enum	e_err
{
	ARG,
	ARG_NEGATIF,
	ZERO_PHILOS,
	MUTEX_INIT,
	MALLOC,
	CREAT_THREAD
};

enum	e_err_type
{
	CONT,
	END
};

void	error(enum e_err err, enum e_err_type type);

void	init(int ac, char **av, t_gen *inf);

int		philo(t_gen *inf);

void	*behavior(void *philo);

int		eating(t_philo *ph);

void	wait_threads(t_gen *inf);

void	print(char *mess, t_philo *ph);

int		compare_time(struct timeval t1, struct timeval t2);

#endif
