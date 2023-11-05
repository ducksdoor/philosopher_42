/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:14:35 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/05 17:14:41 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
