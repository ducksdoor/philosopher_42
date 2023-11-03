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

int	no_gluttony(t_list *phl, int bool_for_deadh, long t_real)
{
	while (phl->philo->need_eat > 0 && bool_for_deadh == 0)
	{
		ft_diner(phl, t_real);
		pthread_mutex_lock(phl->inf->stopmutex);
		if (phl->inf->death != 0)
		{
			bool_for_deadh = 1;
		}
		pthread_mutex_unlock(phl->inf->stopmutex);
	}
	return (0);
}
