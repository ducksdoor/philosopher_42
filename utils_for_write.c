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

void	lookprint(long int t_real, t_list *phl, char *objeto)
{
	printf("\033[1;34m [%ld] \033[0m", t_real);
	printf("El filósofo \033[1;33m%d\033[0m usó: ", phl->philo->name);
	printf("\033[1;32m %s \033[0m \n", objeto);
}

void	lock(t_list *phl)
{
	int	x;

	x = 0;
	while (x < phl->nph)
	{
		pthread_mutex_lock(phl->printmutex);
		phl = phl->next;
		x++;
	}
}

void	unlock(t_list *phl)
{
	int	x;

	x = 0;
	while (x < phl->nph)
	{
		pthread_mutex_unlock(phl->printmutex);
		phl = phl->next;
		x++;
	}
}

void	ft_exit(char *texto, int fd)
{
	write(fd, texto, ft_strlen(texto));
	exit(fd);
}

void	ft_hand(t_list *phl, char *action, long int t_real)
{
	if (0 == ft_strcmp("eat", action))
	{
		printf("[%ld]filosofo %d uso tenedor pana\n",t_real, phl->philo->name);
		phl->philo->need_eat--;
		printf("[%ld]filosofo %d uso comer\n",t_real, phl->philo->name);
		usleep(phl->philo->t_eat);
		t_real = realtime(phl, "restore");
		printf("[%ld]%d uso solto su tenedor\n",t_real, phl->philo->name);
		pthread_mutex_unlock(phl->philo->mutex);
		phl->philo->boolmutex = 0;
		pthread_mutex_unlock(phl->next->philo->mutex);
		printf("[%ld]%d uso soltar tenedor del pana\n",t_real, phl->philo->name);
		phl->next->philo->boolmutex = 0;
	}
	return ;
}
