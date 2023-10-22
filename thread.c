/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/28 20:57:22 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_clean(t_list *phl)
{
	int	x;

	x = 0;
	pthread_mutex_destroy(phl->inf->printmutex);
	while (x < phl->inf->nph)
	{
		pthread_mutex_destroy(phl->philo->mutex);
		pthread_detach(phl->philo->thread);
		phl = phl->next;
		x++;
	}
}

void	ft_select(t_list *phl, long int t_real)
{
	pthread_mutex_lock(phl->philo->mutex);
	prin(t_real, phl, "uso");
	pthread_mutex_lock(phl->next->philo->mutex);
	printf("[%d]", phl->next->philo->name);
	prin(t_real, phl, "uso");
	prin(t_real, phl, "comer");
	usleep(phl->inf->t_eat);
	pthread_mutex_unlock(phl->philo->mutex);
	pthread_mutex_unlock(phl->next->philo->mutex);
	t_real = realtime(phl, "restore");
	prin(t_real, phl, "dormir");
	usleep(phl->inf->t_sleep);
	phl->philo->need_eat--;
	prin(t_real, phl, "pensar");
}

void	*thread_ft(void *arg)
{
	long	t_real;
	t_list	*phl;

	phl = arg;
	if (phl->philo->name % 2 == 0)
		usleep (250);
	t_real = gettimeofday(&phl->clock->aux, NULL);
	while (phl->philo->need_eat > 0)
		ft_select(phl, t_real);
	if (phl->philo->need_eat == 0)
	{
		phl->inf->fully++;
		phl->philo->need_eat--;
	}
	while (phl->inf->fully < phl->inf->nph)
	{
		ft_select(phl, t_real);
	}
	return (NULL);
}
