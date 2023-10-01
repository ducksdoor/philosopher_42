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

void	ft_crono(void)
{
	struct timeval	start_time;
	struct timeval	end_time;
	struct timeval	real_time;
	long			elapsed_time;

	gettimeofday(&start_time, NULL);
	while (1)
	{
		gettimeofday(&end_time, NULL);
		elapsed_time = (end_time.tv_sec - start_time.tv_sec)
			* 1000 + (end_time.tv_usec - start_time.tv_usec);
		real_time.tv_sec = elapsed_time / 1000;
		real_time.tv_usec = elapsed_time % 1000;
		printf("%ld.%06d\n", real_time.tv_sec, real_time.tv_usec);
		usleep(10);
	}
}

/* void	ft_simply_crono(void)
{
	struct timeval	start_time;
	struct timeval	end_time;
	long			elapsed_time;

	gettimeofday(&start_time, NULL);
	while (1)
	{
		gettimeofday(&end_time, NULL);
		elapsed_time = (end_time.tv_sec - start_time.tv_sec);
		printf("%ld\n", elapsed_time);
	}
} */

void	init(t_list *p_list, int argc, char **argv, int x)
{

	p_list->philo = malloc(sizeof(t_philo));
	p_list->philo->name = x;
	p_list->philo->fork = x;
	p_list->philo->mutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(p_list->philo->mutex, NULL) != 0)
		ft_exit("un filosofo a muerto..", 2);
	p_list->philo->time_to_die = ft_atoi(argv[2]);
	p_list->philo->time_to_eat = ft_atoi(argv[3]);
	p_list->philo->time_to_sleep = ft_atoi(argv[4]);
	p_list->philo->n_times_must_eat = 0;
	p_list->philo->thread = malloc(sizeof(pthread_t));
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
