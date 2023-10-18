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

static void	ft_wait(t_list *phl)
{
	while (phl->next->philo->boolmtx == 1)
	{
		usleep (20);
	}
}

void	ft_select(t_list *phl, long int t_real)
{

	while (phl->philo->need_eat > 0)
	{
		t_real = realtime(phl, "normal");
		ft_wait(phl);
		phl->philo->boolmtx = 1;
		pthread_mutex_lock(phl->philo->mutex);
		prin(t_real, phl, "tenedor", "uso");
		if (phl->next->philo->boolmtx == 0)
		{
			phl->next->philo->boolmtx = 1;
			pthread_mutex_lock(phl->next->philo->mutex);
			t_real = realtime(phl, "normal");
			prin(t_real, phl, "tenedor del pana", "uso");
			prin(t_real, phl, "", "comer");
			usleep(phl->inf->t_eat);
			t_real = realtime(phl, "restore");
			phl->philo->need_eat--;
			phl->philo->boolmtx = 0;
			pthread_mutex_unlock(phl->philo->mutex);
			phl->next->philo->boolmtx = 0;
			pthread_mutex_unlock(phl->next->philo->mutex);
			usleep(phl->inf->t_sleep);
		}
	}
}

void	*thread_ft(void *arg)
{
	long	t_real;
	t_list	*phl;

	phl = arg;
	if (phl->philo->name % 2 == 0)
		usleep (20000);
	t_real = gettimeofday(&phl->clock->aux, NULL);
	if (phl->philo->need_eat > 0)
		ft_select(phl, t_real);
	if (phl->philo->need_eat == 0)
		ft_fully(phl);
	if (phl->inf->fully == phl->inf->nph)
		ft_exit("Todos los filos han comido", 2);
	pthread_mutex_destroy(phl->philo->mutex);
	ft_exit("mutex destruido\n", 1);
	exit(1);
}
