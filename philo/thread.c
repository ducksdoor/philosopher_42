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

void	ft_diner(t_list *phl)
{
	pthread_mutex_lock(phl->philo->mutex);
	take_and_eat(phl);
	dream(phl->inf->t_eat, phl);
	pthread_mutex_unlock(phl->philo->mutex);
	pthread_mutex_unlock(phl->next->philo->mutex);
	color_print(phl, "dormir");
	dream(phl->inf->t_sleep, phl);
	color_print(phl, "pensar");
}

void	start_diner(t_list *phl)
{
	int	bool_for_dead;

	bool_for_dead = 0;
	bool_for_dead = no_gluttony(phl, bool_for_dead);
	if (phl->philo->need_eat == 0 && bool_for_dead == 0)
		ft_fully(phl);
	if (bool_for_dead == 0)
		segurity_for_finish(phl, bool_for_dead);
	return ;
}

void	*thread_ft(void *arg)
{
	long	time_real;
	t_list	*phl;

	phl = arg;
	time_real = gettimeofday(&phl->clock->aux, NULL);
	phl->philo->t_real = time_real;
	if (phl->philo->name % 2 == 0)
		usleep(1600);
	start_diner(phl);
	return (NULL);
}
