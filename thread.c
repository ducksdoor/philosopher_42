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

void	ft_data_clean(t_list *phl)
{
	free(phl->inf->stopmutex);
	free(phl->inf);
}

void	ft_clean(t_list *phl)
{
	t_list	*aux;
	t_list	*start;

	ft_data_clean(phl);
	start = phl;
	while (phl)
	{
		pthread_mutex_destroy(phl->philo->mutex);
		pthread_detach(phl->philo->thread);
		aux = phl;
		phl = phl->next;
		free(aux->clock);
		aux->clock = NULL;
		free(aux);
		if (phl == start)
			return ;
	}
}

void	ft_diner(t_list *phl, long t_real)
{
	pthread_mutex_lock(phl->philo->mutex);
	take_and_eat(phl, t_real);
	dream(phl->inf->t_eat, phl, t_real);
	pthread_mutex_unlock(phl->philo->mutex);
	pthread_mutex_unlock(phl->next->philo->mutex);
	color_print(t_real, phl, "dormir");
	dream(phl->inf->t_sleep, phl, t_real);
	color_print(t_real, phl, "pensar");
}

void	start_diner(t_list *phl)
{
	int	bool_for_dead;

	bool_for_dead = 0;
	bool_for_dead = no_gluttony(phl, bool_for_dead, phl->philo->t_real);
	if (phl->philo->need_eat == 0 && bool_for_dead == 0)
		ft_fully(phl);
	if (bool_for_dead == 0)
		segurity_for_finish(phl, bool_for_dead, phl->philo->t_real);
	return ;
}

void	*thread_ft(void *arg)
{
	t_list	*phl;

	phl = arg;
	if (phl->philo->name % 2 == 0)
		usleep(1600);
	start_diner(phl);
	return (NULL);
}
