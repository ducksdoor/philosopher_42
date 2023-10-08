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

void	eat(t_list *x, int t_juego, long t_real)
{
	x->next->philo->boolmutex = 1;
	pthread_mutex_lock(x->next->philo->mutex);
	printf("f[%ld]filosofo %d uso tenedor amigo\n",t_real, x->philo->name);
	x->philo->n_times_must_eat--;
	printf("f[%ld]filosofo %d uso comer\n",t_real, x->philo->name);
	usleep(x->philo->t_eat);
	printf("TR->[%ld], TJ->[%d]. Soy el filo %d, me quedan %d comidas y Estoy vivo!\n",t_real, t_juego, x->philo->name, x->philo->n_times_must_eat);
	pthread_mutex_unlock(x->philo->mutex);
	x->philo->boolmutex = 0;
	printf("f[%ld]filosofo %d uso soltar tenedor\n",t_real, x->philo->name);
	pthread_mutex_unlock(x->next->philo->mutex);
	printf("f[%ld]filosofo %d uso soltar tenedor de mi pana\n\n",t_real, x->philo->name);
	x->next->philo->boolmutex = 0;
	return ;
}

void	die(t_list	*list, int x)
{
	printf("El filoso n [%d] ha muerto\n", list->philo->name);
	printf("el tiempo de muerte es : %d\n", x);
	pthread_mutex_destroy(list->philo->mutex);
	ft_exit("un filosofo a muerto..", 1);
	exit(1);
}

void	lock(t_list *phl)
{
	int	x;

	x = 0;
	while (x < phl->nph)
	{
		pthread_mutex_lock(phl->printmutex);
		phl = phl->next;
		x++;
	}
}

void	unlock(t_list *phl)
{
	int	x;

	x = 0;
	while (x < phl->nph)
	{
		pthread_mutex_unlock(phl->printmutex);
		phl = phl->next;
		x++;
	}
}

void	fool(t_list *phl)
{
	long			t_juego;
	long int		t_real;

	gettimeofday(&phl->clock->start, NULL);
	gettimeofday(&phl->clock->aux, NULL);
	if (phl->philo->name % 1 == 0)
		usleep (10);
	while (phl->philo->n_times_must_eat >= 0)
	{
		gettimeofday(&phl->clock->end, NULL);
		t_real = ft_time(phl->clock->start, phl->clock->end);
		t_juego = ft_time(phl->clock->aux, phl->clock->end);
		if (t_juego >= phl->philo->t_die)
			die(phl, t_real);
		else if (phl->philo->n_times_must_eat == 0)
		{
			pthread_mutex_destroy(phl->philo->mutex);
			ft_exit("mutex destruido\n", 1);
		}
		else
		{
			if (phl->next->philo->boolmutex == 0 && phl->philo->boolmutex == 0)
			{
				lock(phl);
				phl->philo->boolmutex = 1;
				pthread_mutex_lock(phl->philo->mutex);
				printf("f[%ld]filoso %d uso tenedor\n",t_real, phl->philo->name);
				if (phl->next->philo->boolmutex == 0)
				{
					gettimeofday(&phl->clock->aux, NULL);
					eat(phl, t_juego, t_real);
				}
				else
				{
					pthread_mutex_unlock(phl->philo->mutex);
					phl->philo->boolmutex = 0;
					printf("\nf[%d]desbloqueado mi mutex\n\n", phl->philo->name);
				}
				phl->philo->boolmutex = 0;
				unlock(phl);
				usleep(phl->philo->t_sleep);
			}
		}
	}
	exit(1);
}
/* 			if (3 == pthread_mutex_lock(phl->next->philo->mutex))
				pthread_mutex_destroy(phl->philo->mutex); */

void	*thread_ft(void *arg)
{
	fool(arg);
	exit(1);
}
