/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_alone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:20:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 23:20:33 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_alone(t_list *phl, long t_real)
{
	pthread_mutex_lock(phl->philo->mutex);
	prin(t_real, phl, "uso");
	while (phl->inf->death == 0)
	{
		t_real = realtime(phl, "normal");
	}
}
