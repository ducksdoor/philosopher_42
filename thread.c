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

void	ft_data_clean(t_list *phl)
{
	free(phl->inf->printmutex);
	free(phl->inf);
}

void	ft_clean(t_list *phl)
{
	t_list	*aux;
	t_list	*start;

	start = phl;
	while (phl)
	{
		pthread_mutex_destroy(phl->philo->mutex);
		pthread_detach(phl->philo->thread);
		aux = phl;
		phl = phl->next;

		free(aux->clock);
		aux->clock = NULL;
		free(aux);

		if (phl == start)
			return ;
	}
}

void	ft_select(t_list *phl, long int t_real)
{
	//printf("has nacido mal%p\n", phl->next);
	pthread_mutex_lock(phl->philo->mutex);
	prin(t_real, phl, "uso");
	pthread_mutex_lock(phl->next->philo->mutex);
	//printf("[%d]", phl->next->philo->name);
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
	usleep(150);
	ft_wait_for_start(phl);
	usleep(150);
	if (phl->philo->name % 2 == 0)
		usleep (150);
	t_real = gettimeofday(&phl->clock->aux, NULL);
	while (phl->philo->need_eat > 0)
		ft_select(phl, t_real);
	if (phl->philo->need_eat == 0)
	{
		pthread_mutex_lock(phl->inf->printmutex);
		phl->inf->fully++;
		pthread_mutex_unlock(phl->inf->printmutex);
		phl->philo->need_eat--;
	}
	ft_wait_for_finish(phl, t_real);
	return (NULL);
}
