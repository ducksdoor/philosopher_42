/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_eat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:29:19 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 23:29:21 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	take_and_eat(t_list *phl)
{
	color_print(phl, "uso");
	pthread_mutex_lock(phl->next->philo->mutex);
	color_print(phl, "uso");
	color_print(phl, "comer");
	realtime(phl, "restore");
	dream(phl->inf->t_eat, phl);
	phl->philo->need_eat--;
	if (phl->philo->need_eat == 0)
		ft_fully(phl);
}
