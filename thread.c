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

void	eat(t_list *x, long t_real, char *condicion)
{
	x->next->philo->boolmtx = 1;
	pthread_mutex_lock(x->next->philo->mutex);
	t_real = realtime(x, "normal");
	ft_hand(x, "eat", t_real);
	lookprint(t_real, x, "dormir", "dormir");
	t_real = realtime(x, "normal");
	usleep(x->philo->t_sleep);
	lookprint(t_real, x, condicion, "pensar");
	return ;
}

void	posible_eat(t_list *phl, long int t_real, char *condicion)
{
	t_real = realtime(phl, "normal");
	if (phl->philo->boolmtx == 0)
	{
		phl->philo->boolmtx = 1;
		pthread_mutex_lock(phl->philo->mutex);
		lookprint(t_real, phl, "tenedor", "uso");
		if (phl->next->philo->boolmtx == 0)
		{
			eat(phl, t_real, condicion);
			phl->philo->boolmtx = 0;
			usleep(phl->philo->t_sleep);
		}
		else
		{
			pthread_mutex_unlock(phl->philo->mutex);
			phl->philo->boolmtx = 0;
			lookprint(t_real, phl, "tenedor(salida else)", "soltar");
		}
	}
	else
		usleep(10);
}

void	ft_select(t_list *phl, long int t_real)
{
	if (phl->philo->name % 1 == 0 && t_real == 0)
		usleep (50);
	if (phl->philo->need_eat > 0)
	{
		while (phl->philo->need_eat > 0)
		{
			t_real = realtime(phl, "normal");
			if (phl->next->philo->boolmtx == 0 && phl->philo->boolmtx == 0)
				posible_eat(phl, t_real, "limitado");
			usleep(10);
		}
	}
	if (phl->philo->need_eat == -1)
	{
		while (1)
		{
			t_real = realtime(phl, "normal");
			if (phl->next->philo->boolmtx == 0 && phl->philo->boolmtx == 0)
				posible_eat(phl, t_real, "infinito");
			usleep(10);
		}
	}
}

void	*thread_ft(void *arg)
{
	long int	t_real;
	t_list		*phl;

	phl = arg;
	t_real = gettimeofday(&phl->clock->aux, NULL);
	ft_select(phl, t_real);
	pthread_mutex_destroy(phl->philo->mutex);
	ft_exit("mutex destruido\n", 1);
	exit(1);
}
