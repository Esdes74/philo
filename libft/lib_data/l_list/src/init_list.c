/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:55:02 by eslamber          #+#    #+#             */
/*   Updated: 2023/11/16 16:26:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_list.h"

t_list	*init_list(t_list *lst)
{
	if (lst == 0)
		return (write(2, "Error : fct init_list : lst null\n", 33), NULL);
	lst->len = 0;
	lst->type_lst = LIST;
	lst->head = 0;
	lst->tail = 0;
	return (lst);
}
