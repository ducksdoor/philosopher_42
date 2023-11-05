/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:37:06 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/25 23:37:08 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	color_print(long t_rel, t_list *phl, char *act)
{
	t_rel = realtime(phl, "normal");
	pthread_mutex_lock(phl->inf->stopmutex);
	if (phl->inf->death == 0 && phl->inf->fully != phl->inf->nph)
	{
		printf("\n \033[1;34m [[%ld]] \033[0m", t_rel);
		printf("	\033[1;33m%d\033[0m", phl->philo->name);
		if (0 == ft_strcmp("comer", act))
			printf("\033[1;32m is eating \033[0m \n");
		if (0 == ft_strcmp("dormir", act))
			printf(" \033[1;36m is sleeping \033[0m \n");
		if (0 == ft_strcmp("uso", act))
			printf("\033[1;35m  has taken a fork \033[0m \n");
		if (0 == ft_strcmp("pensar", act))
		{
			printf("\033[1;31m is thinking\033[0m");
			printf(" quedan\033[1;32m %d \033[0m comidas\n", phl->philo->need_eat);
		}
	}
	pthread_mutex_unlock(phl->inf->stopmutex);
}
