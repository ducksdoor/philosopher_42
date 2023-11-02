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

void	ft_select(t_list *phl, long int t_real)
{
	pthread_mutex_lock(phl->philo->mutex);
	take_and_eat(phl, t_real);
	usleep(phl->inf->t_eat);
	pthread_mutex_unlock(phl->philo->mutex);
	pthread_mutex_unlock(phl->next->philo->mutex);
	prin(t_real, phl, "dormir");
	usleep(phl->inf->t_sleep);
	prin(t_real, phl, "pensar");
}

static void	start_diner(t_list *phl, long t_real)
{
	int	bool_for_deadh;

	bool_for_deadh = 0;
	if (phl->inf->nph == 1)
	{
		philo_alone(phl, t_real);
		return ;
	}
	bool_for_deadh = no_gluttony(phl, bool_for_deadh, t_real);
	if (phl->philo->need_eat == 0 && bool_for_deadh == 0)
		ft_fully(phl);
	if (bool_for_deadh == 0)
		segurity_for_finish(phl, t_real);
}

void	*thread_ft(void *arg)
{
	long	t_real;
	t_list	*phl;

	phl = arg;
	t_real = gettimeofday(&phl->clock->aux, NULL);
	if (phl->philo->name % 2 == 0)
		usleep (1600);
	start_diner(phl, t_real);
	return (NULL);
}
