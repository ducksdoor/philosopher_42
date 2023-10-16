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

void	init(t_list *p_list, char **argv, int x, pthread_mutex_t *printmtx)
{
	p_list->philo = malloc(sizeof(t_philo));
	p_list->clock = malloc(sizeof(t_time));
	gettimeofday(&p_list->clock->start, NULL);
	p_list->philo->boolmtx = 0;
	p_list->philo->name = x;
	p_list->philo->mute_fork = x;
	p_list->philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(p_list->philo->mutex, NULL) != 0)
		ft_exit("un filosofo a muerto..", 2);
	p_list->nph = ft_atoi(argv[1]);
	p_list->philo->t_die = (ft_atoi(argv[2]));
	p_list->philo->t_eat = (ft_atoi(argv[3]) * 1000);
	p_list->philo->t_sleep = (ft_atoi(argv[4]) * 1000);
	p_list->philo->need_eat = -1;
	p_list->philo->thread = malloc(sizeof(pthread_t));
	p_list->printmutex = printmtx;
	if (argv[5])
		p_list->philo->need_eat = ft_atoi(argv[5]);
	if (0 != pthread_create(&p_list->philo->thread, NULL, thread_ft, p_list))
		ft_exit("error en la creación del hilo", 2);
}
