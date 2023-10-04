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

void	eat(t_list *x, int t_juego, int t_pasado)
{
	x->next->philo->boolmutex = 1;
	pthread_mutex_lock(x->next->philo->mutex);
	printf("f[%d]he cogido el segundo tenedor\n", x->philo->name);
	x->philo->n_times_must_eat--;
	printf("f[%d]he comido\n", x->philo->name);
	usleep(x->philo->t_eat);
	printf("TR->[%d], TJ->[%d]. Soy el filo %d, me quedan %d comidas y Estoy vivo!\n",t_pasado, t_juego, x->philo->name, x->philo->n_times_must_eat);
	pthread_mutex_unlock(x->philo->mutex);
	x->philo->boolmutex = 0;
	printf("f[%d]he desbloqueado el mutex del siguiente hilo\n", x->philo->name);
	pthread_mutex_unlock(x->next->philo->mutex);
	x->next->philo->boolmutex = 0;
	printf("f[%d]he desbloqueado mi mutex\n\n", x->philo->name);
	usleep(x->philo->t_sleep);
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

void	fool(t_list *phl, pthread_mutex_t *windows, int wbool)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	aux;
	long			t_juego;
	long			t_pasado;

	gettimeofday(&start, NULL);
	gettimeofday(&aux, NULL);
	if (phl->philo->name % 1 == 0)
		usleep (10);
	while (phl->philo->n_times_must_eat > 0)
	{
		gettimeofday(&end, NULL);
		t_pasado = (end.tv_usec - start.tv_usec);
		t_juego = (end.tv_usec - aux.tv_usec);
/* 		if (wbool == 0)
		{
			wbool = 1;
			pthread_mutex_lock(windows); */
		if (t_juego >= phl->philo->t_die)
			die(phl, t_juego);
		else if (phl->philo->boolmutex == 0 && phl->next->philo->boolmutex == 0)
		{
			if (phl->philo->boolmutex == 0)
			{
				phl->philo->boolmutex = 1;
				pthread_mutex_lock(windows);
				pthread_mutex_lock(phl->philo->mutex);
				printf("f[%d]he cogido un tenedor\n", phl->philo->name);
				if (phl->next->philo->boolmutex == 0)
				{
					gettimeofday(&aux, NULL);
					eat(phl, t_juego, t_pasado);
				}
				else
				{
					pthread_mutex_unlock(phl->philo->mutex);
					phl->philo->boolmutex = 0;
					printf("\nf[%d]desbloqueado mi mutex\n\n", phl->philo->name);
					usleep(10);
				}
				pthread_mutex_unlock(windows);
			}
			else if (3 == pthread_mutex_lock(phl->next->philo->mutex))
				pthread_mutex_destroy(phl->philo->mutex);
		}
/* 			pthread_mutex_unlock(windows);
		} */
			
		wbool = 2;
	}
	exit(1);
}

void	*thread_ft(void *arg)
{
	pthread_mutex_t *windo;
	int				wbool;

	wbool = 2;
	windo = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(windo, NULL) != 0)
		ft_exit("no se ha creado la variable windo", 2);
/* 	wbool = 0; */
	fool(arg, &windo, &wbool);
	exit(1);
}
