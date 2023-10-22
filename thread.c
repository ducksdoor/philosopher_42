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

/* static void	ft_wait(t_list *phl)
{
	while (phl->next->philo->boolmtx == 1)
	{
		usleep (20);
	}
} */
//

void	ft_select(t_list *phl, long int t_real)
{
	pthread_mutex_lock(phl->philo->mutex);
	//printf("Puntero tenerdor%p\n", phl->philo->mutex);
	//printf("Puntero tenerdor%p\n", phl->next->philo->mutex);
	prin(t_real, phl, "tenedor", "uso");
	pthread_mutex_lock(phl->next->philo->mutex);
	prin(t_real, phl, "tenedor del pana", "uso");
/* 	block(phl, t_real); */
	prin(t_real, phl, "", "comer");
	usleep(phl->inf->t_eat);
	phl->philo->boolmtx = 0;
	pthread_mutex_unlock(phl->philo->mutex);
	phl->next->philo->boolmtx = 0;
	pthread_mutex_unlock(phl->next->philo->mutex);
	t_real = realtime(phl, "restore");
	prin(t_real, phl, "", "dormir");
	usleep(phl->inf->t_sleep);
	phl->philo->need_eat--;
	prin(t_real, phl, "", "pensar");
/* 	if (phl->philo->need_eat == 0)
	{
		phl->inf->fully++;
		phl->philo->need_eat--;
	} */
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
		ft_fully(phl);
	while (phl->inf->fully < phl->inf->nph)
		ft_select(phl, t_real);
	ft_exit("Todos los filos han comido", 2);
/* 	pthread_mutex_destroy(phl->philo->mutex);
	ft_exit("mutex destruido\n", 1); */
	exit(1);
}
