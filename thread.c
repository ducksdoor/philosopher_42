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
	printf("[%ld]filosofo %d uso dormir\n",t_real, x->philo->name);
	t_real = realtime(x, "normal");
	usleep(x->philo->t_sleep);
	//unlock(x);
	//lock(x);
	printf("[%ld]filosofo %d uso pensar (quedan %d eats).\n",
		t_real, x->philo->name, x->philo->need_eat);
	return ;
}

static void	posible_eat(t_list *phl, long int t_real)
{
	t_real = realtime(phl, "normal");
	if (phl->philo->boolmutex == 0)
	{
		phl->philo->boolmutex = 1;
		pthread_mutex_lock(phl->philo->mutex);
		//lock(phl);
		lookprint(t_real, phl, "tenedor");
		printf("[%ld]filoso %d uso tenedor\n",t_real, phl->philo->name);
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
			printf("f[%ld]filosofo %d suelta mutex(salida else)\n", t_real, phl->philo->name);
		}
	}
	else
		usleep(10);
	//unlock(phl);
}

void	fool(t_list *phl)
{
	long int		t_real;

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
	//exit(1);
}
/* 			if (3 == pthread_mutex_lock(phl->next->philo->mutex))
				pthread_mutex_destroy(phl->philo->mutex); */

void	*thread_ft(void *arg)
{
	fool(arg);
	exit(1);
}
