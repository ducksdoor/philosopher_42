/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:37:06 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/25 23:37:08 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lookprint(long int t_real, t_list *phl, char *objeto, char *action)
{
	pthread_mutex_lock(phl->printmutex);
	printf("\n \033[1;34m [%ld] \033[0m", t_real);
	printf("El filósofo numero: \033[1;33m%d\033[0m", phl->philo->name);
	if (0 == ft_strcmp("comer", action))
		printf("\033[1;32m esta comiendo \033[0m \n");
	if (0 == ft_strcmp("dormir", action))
		printf(" \033[1;32m esta durmiendo \033[0m \n");
	if (0 == ft_strcmp("uso", action))
		printf(" uso \033[1;32m %s \033[0m \n", objeto);
	if (0 == ft_strcmp("soltar", action))
		printf(" solto\033[1;32m %s \033[0m \n", objeto);
	if (0 == ft_strcmp("pensar", action))
	{
		printf(" esta \033[1;32m pensando \033[0m");
		printf(" quedan\033[1;32m %d \033[0m comidas\n", phl->philo->need_eat);
	}
	pthread_mutex_unlock(phl->printmutex);
}

void	ft_exit(char *texto, int fd)
{
	write(fd, texto, ft_strlen(texto));
	exit(2);
}

void	ft_hand(t_list *phl, char *action, long int t_real)
{
	if (0 == ft_strcmp("eat", action))
	{
		lookprint(t_real, phl, "tenedor del pana", "uso");
		phl->philo->need_eat--;
		lookprint(t_real, phl, "", "comer");
		usleep(phl->philo->t_eat);
		t_real = realtime(phl, "restore");
		lookprint(t_real, phl, "su tenedor", "soltar");
		pthread_mutex_unlock(phl->philo->mutex);
		phl->philo->boolmutex = 0;
		pthread_mutex_unlock(phl->next->philo->mutex);
		lookprint(t_real, phl, "tenedor del pana", "soltar");
		phl->next->philo->boolmutex = 0;
	}
	return ;
}
