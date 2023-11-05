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

void	take_and_eat(t_list *phl, long t_real)
{
	color_print(t_real, phl, "uso");
	pthread_mutex_lock(phl->next->philo->mutex);
	color_print(t_real, phl, "uso");
	color_print(t_real, phl, "comer");
	phl->philo->need_eat--;
	t_real = realtime(phl, "restore");
}
