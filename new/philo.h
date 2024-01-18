/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:07:12 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/18 16:52:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include "libft/libft.h"

typedef struct s_gen
{
	size_t	nb_philo;
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	nb_eat;
}	t_gen;

enum	e_err
{
	ARG,
	ARG_NEGATIF
};

enum	e_err_type
{
	CONT,
	END
};

void	error(enum e_err err, enum e_err_type type);

#endif
