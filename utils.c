/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:39:38 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/25 20:39:43 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init(t_list *p_list, int argc, char **argv, int x)
{
	p_list->philo = malloc(sizeof(t_philo));
	p_list->clock = malloc(sizeof(t_time));
	gettimeofday(&p_list->clock->start, NULL);
	p_list->philo->boolmutex = 0;
	p_list->philo->name = x;
	p_list->philo->mute_fork = x;
	p_list->philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(p_list->philo->mutex, NULL) != 0)
		ft_exit("un filosofo a muerto..", 2);
	p_list->nph = ft_atoi(argv[1]);
	p_list->philo->t_die = (ft_atoi(argv[2]));
	p_list->philo->t_eat = (ft_atoi(argv[3]) * 1000);
	p_list->philo->t_sleep = (ft_atoi(argv[4]) * 1000);
	p_list->philo->n_times_must_eat = -1;
	p_list->philo->thread = malloc(sizeof(pthread_t));
	p_list->printmutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(p_list->printmutex, NULL) != 0)
		ft_exit("no se creó un hilo", 2);
	if (argc == 6)
		p_list->philo->n_times_must_eat = ft_atoi(argv[5]);
	if (0 != pthread_create(&p_list->philo->thread, NULL, thread_ft, p_list))
		ft_exit("error en la creación del hilo", 2);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
