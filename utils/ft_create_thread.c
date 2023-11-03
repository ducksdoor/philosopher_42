/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:01:13 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 19:01:15 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_create_thread(t_list *phl)
{
	int	x;

	x = 0;
	if (phl->inf->nph > 1)
	{
		while (x < phl->inf->nph)
		{
			if (0 != pthread_create(&phl->philo->thread, NULL, thread_ft, phl))
				return ;
			phl = phl->next;
			x++;
		}
	}
	if (phl->inf->nph == 1)
	{
		if (0 != pthread_create(&phl->philo->thread, NULL, philo_alone, phl))
			return ;
	}
}
