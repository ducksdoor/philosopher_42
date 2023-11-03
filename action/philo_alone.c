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

void	*philo_alone(void *arg)
{
	long	t_real;
	t_list	*phl;

	phl = arg;
	t_real = gettimeofday(&phl->clock->aux, NULL);

	pthread_mutex_lock(phl->philo->mutex);
	prin(t_real, phl, "uso");
	while (phl->inf->death == 0)
		t_real = realtime(phl, "normal");
	return (NULL);
}
