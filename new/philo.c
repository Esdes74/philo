/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:47:29 by eslamber          #+#    #+#             */
/*   Updated: 2024/01/25 14:01:37 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_gen *inf)
{
    inf->tab_philo = malloc(sizeof(t_philo) * inf->nb_philo);
    if (inf->tab_philo == NULL)
        return (error(MALLOC, CONT), 1);
}
