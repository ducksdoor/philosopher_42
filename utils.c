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
			* 1000000 + (end_time.tv_usec - start_time.tv_usec);
		real_time.tv_sec = elapsed_time / 1000000;
		real_time.tv_usec = elapsed_time % 1000000;
		printf("%ld.%06d\n", real_time.tv_sec, real_time.tv_usec);
		usleep(100000);
	}
}

void	ft_simply_crono(void)
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
}

void	init(t_list *philo_list, int argc, char **argv)
{
	philo_list->philo = malloc(sizeof(t_philo));
	philo_list->philo->n_philosophers = ft_atoi(argv[1]);
	philo_list->philo->time_to_die = ft_atoi(argv[2]);
	philo_list->philo->time_to_eat = ft_atoi(argv[3]);
	philo_list->philo->time_to_sleep = ft_atoi(argv[4]);
	philo_list->philo->n_times_each_philosopher_must_eat = 0;
	if (argc == 6)
		philo_list->philo->n_times_each_philosopher_must_eat = ft_atoi(argv[5]);
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
