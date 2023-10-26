/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/28 20:57:22 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_inf(t_inf *inf, char **argv, pthread_mutex_t *printmutex)
{
/* 	inf->born = 0; */
	inf->nph = ft_atoi(argv[1]);
	inf->t_die = (ft_atoi(argv[2]));
	inf->t_eat = (ft_atoi(argv[3]));
	inf->t_sleep = (ft_atoi(argv[4]));
	inf->fully = 0;
	inf->printmutex = printmutex;
	gettimeofday(&inf->start, NULL);
}

void	init(t_list *phl, char **argv, int x, t_inf *inf)
{
	phl->next = NULL;
	phl->inf = inf;
	phl->philo = malloc(sizeof(t_philo));
	phl->clock = malloc(sizeof(t_time));
	phl->philo->name = x;
	phl->philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (!phl->philo->mutex || !phl->clock || !phl->clock)
		return ;
	if (pthread_mutex_init(phl->philo->mutex, NULL) != 0)
		ft_exit("no se pudo crear un tenedor", 2); //no se puede usar exit
	phl->philo->need_eat = -1;
	if (argv[5])
		phl->philo->need_eat = ft_atoi(argv[5]);
	pthread_mutex_lock(phl->inf->printmutex);
	phl->inf->born++;
	pthread_mutex_unlock(phl->inf->printmutex);
	if (0 != pthread_create(&phl->philo->thread, NULL, thread_ft, phl))
		ft_exit("error en la creación del hilo", 2);
}// eeeeexiiiiit
