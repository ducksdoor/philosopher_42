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

#include "../philosophers.h"

void	init_inf(t_inf *inf, char **argv, pthread_mutex_t *stopmutex)
{
	inf->nph = ft_atoi(argv[1]);
	inf->t_die = (ft_atoi(argv[2]));
	inf->t_eat = (ft_atoi(argv[3]));
	inf->t_sleep = (ft_atoi(argv[4]));
	inf->fully = 0;
	inf->death = 0;
	inf->stopmutex = stopmutex;
	gettimeofday(&inf->start, NULL);
}

void	init(t_list *phl, char **argv, int x, t_inf *inf)
{
	if (!phl)
		return ;
	phl->next = NULL;
	phl->inf = inf;
	phl->philo = malloc(sizeof(t_philo));
	phl->clock = malloc(sizeof(t_time));
	phl->philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (!phl->philo || !phl->clock || !phl->philo->mutex)
		ft_big_free(phl);
	else
	{
		phl->philo->fat = 1;
		phl->philo->name = x;
		if (pthread_mutex_init(phl->philo->mutex, NULL) != 0)
		{
			ft_big_free(phl);
			return ;
		}
		phl->philo->need_eat = -1;
		if (argv[5])
			phl->philo->need_eat = ft_atoi(argv[5]);
	}
}
