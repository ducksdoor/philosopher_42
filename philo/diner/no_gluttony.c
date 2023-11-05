/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_gluttony.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:42:24 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 23:42:32 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	no_gluttony(t_list *phl, int bool_for_dead)
{
	while (phl->philo->need_eat > 0 && bool_for_dead == 0)
	{
		ft_diner(phl);
		pthread_mutex_lock(phl->inf->stopmutex);
		if (phl->inf->death != 0)
			bool_for_dead = 1;
		pthread_mutex_unlock(phl->inf->stopmutex);
		if (bool_for_dead == 1)
			return (1);
	}
	return (0);
}
