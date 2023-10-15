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

void	die(t_list	*list, int x)
{
	printf("El filoso n [%d] ha muerto\n", list->philo->name);
	printf("el tiempo de muerte es : %d\n", x);
	pthread_mutex_destroy(list->philo->mutex);
	ft_exit("un filosofo a muerto..", 1);
	exit(1);
}

void	eat(t_list *x, long t_real)
{
	x->next->philo->boolmutex = 1;
	pthread_mutex_lock(x->next->philo->mutex);
	t_real = realtime(x, "normal");
	ft_hand(x, "eat", t_real);
	lookprint(t_real, x, "dormir", "dormir");
	t_real = realtime(x, "normal");
	usleep(x->philo->t_sleep);
	lookprint(t_real, x, "", "pensar");
	return ;
}

static void	posible_eat(t_list *phl, long int t_real)
{
	t_real = realtime(phl, "normal");
	if (phl->philo->boolmutex == 0)
	{
		phl->philo->boolmutex = 1;
		pthread_mutex_lock(phl->philo->mutex);
		lookprint(t_real, phl, "tenedor", "uso");
		if (phl->next->philo->boolmutex == 0)
		{
			eat(phl, t_real);
			phl->philo->boolmutex = 0;
			usleep(phl->philo->t_sleep);
		}
		else
		{
			pthread_mutex_unlock(phl->philo->mutex);
			phl->philo->boolmutex = 0;
			lookprint(t_real, phl, "tenedor(salida else)", "soltar");
		}
	}
	else
		usleep(10);
}

static void	select(t_list *phl)
{

}

void	*thread_ft(void *arg)
{
	long int	t_real;
	t_list		*phl;

	phl = arg;
	t_real = 0;
	gettimeofday(&phl->clock->aux, NULL);
	if (phl->philo->name % 1 == 0 && t_real == 0)
		usleep (50);
	while (phl->philo->need_eat > 0)
	{
		t_real = realtime(phl, "normal");
/* 		if (phl->philo->need_eat == 0)
		{
			pthread_mutex_destroy(phl->philo->mutex);
			ft_exit("mutex destruido\n", 1);
		} */
 		if (phl->next->philo->boolmutex == 0 && phl->philo->boolmutex == 0)
			posible_eat(phl, t_real);
		usleep(10);
	}
	exit(1);
}
/* 			if (3 == pthread_mutex_lock(phl->next->philo->mutex))
				pthread_mutex_destroy(phl->philo->mutex); */

