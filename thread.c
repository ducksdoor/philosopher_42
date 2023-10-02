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

void	*die(t_list	*list, int x)
{
	printf("El filoso n [%d] ha muerto\n", list->philo->name);
	printf("el tiempo de muerte es : %d\n", x);
	pthread_mutex_destroy(list->philo->mutex);
	ft_exit("un filosofo a muerto..", 1);
	exit(1);
}

void	*thread_ft(void *arg)
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	aux;
	t_list			*x;
	int				t_juego;
	int				t_pasado;
	int				t_trampa;

	gettimeofday(&start, NULL);
	gettimeofday(&aux, NULL);

	x = arg;
	t_pasado = 0;
	t_trampa = 0;
/* 	if (x->philo->name % 1 == 0)
		usleep (5); */
	while (x->philo->n_times_must_eat > 0) 
	/* || x->philo->n_times_must_eat < 0) */
	{
		gettimeofday(&end, NULL);
		t_pasado = (end.tv_usec - start.tv_usec);
		t_juego = (end.tv_usec - aux.tv_usec);

		if (t_juego >= x->philo->t_die)
			die(x, t_juego);
		else if (t_juego < x->philo->t_die)
		{
			if (0 == pthread_mutex_lock(x->philo->mutex))
			{
				printf("he bloqueado mi mutex\n");
				if (0 == pthread_mutex_lock(x->next->philo->mutex))
				{
					printf("he bloqueado el mutex del siguiente hilo\n");
					t_trampa = t_trampa + x->philo->t_eat;
					gettimeofday(&aux, NULL);
					x->philo->n_times_must_eat--;
					printf("he comido\n");
					usleep(x->philo->t_eat);
/* 					printf("mas pruebas con el crono [%d]\n", (t_juego - x->start_time)); */
					printf("TR->[%d], TJ->[%d], TT->[%d] Soy el filo %d, me quedan %d comidas y Estoy vivo!\n",t_pasado, t_juego, t_trampa, x->philo->name, x->philo->n_times_must_eat);
					pthread_mutex_unlock(x->next->philo->mutex);
					printf("he desbloqueado el mutex del siguiente hilo\n");
					pthread_mutex_unlock(x->philo->mutex);
					printf("he desbloqueado mi mutex\n\n");
					usleep(x->philo->t_sleep);
				}	
				else
				{
					pthread_mutex_unlock(x->philo->mutex);
					printf("|he desbloqueado mi mutex\n\n");
					usleep(100);
				}
			}
			if (3 == pthread_mutex_lock(x->next->philo->mutex))
			{
				pthread_mutex_destroy(x->philo->mutex);
				ft_exit("Creador, un filosofo, hermano mio a muerto, por tanto, termino el ejercicio", 1);
			}
			pthread_mutex_unlock(x->philo->mutex);
			printf("he desbloqueado mi mutex\n\n");
			usleep(100);
		}
	}
	ft_exit("\nEl programa se terminó con exito, todos los filos comieron\n", 1);
	exit(1);
}
