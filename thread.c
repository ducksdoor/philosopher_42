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
	free(phl->inf->stopmutex);
	free(phl->inf);
}

void	ft_clean(t_list *phl)
{
	t_list	*aux;
	t_list	*start;

	ft_data_clean(phl);
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
	pthread_mutex_lock(phl->philo->mutex);
	prin(t_real, phl, "uso");
	if (phl->inf->nph > 1)
	{
		pthread_mutex_lock(phl->next->philo->mutex);
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
	else
	{
		pthread_mutex_unlock(phl->philo->mutex);
		t_real = realtime(phl, "normal");
		usleep(1000);
	}
}

static void	process(int x, t_list *phl, long t_real)
{
	while (phl->philo->need_eat > 0 && x == 0)
	{
		ft_select(phl, t_real);
		pthread_mutex_lock(phl->inf->stopmutex);
		if (phl->inf->death != 0)
			x = 1;
		pthread_mutex_unlock(phl->inf->stopmutex);
	}
	if (phl->philo->need_eat == 0 && x == 0)
		ft_fully(phl);
	if (x == 0)
		ft_wait_for_finish(phl, t_real);
}

void	*thread_ft(void *arg)
{
	long	t_real;
	t_list	*phl;
	int		x;

	x = 0;
	phl = arg;
	usleep(150);
	ft_wait_for_start(phl);
	usleep(150);
	if (phl->philo->name % 2 == 0)
		usleep (150);
	t_real = gettimeofday(&phl->clock->aux, NULL);
	process(x, phl, t_real);
	return (NULL);
}
