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

void	prin(long t_rel, t_list *phl, char *ob_con, char *act)
{
	t_rel = realtime(phl, "normal");
	if (phl->clock->t_juego >= phl->inf->t_die)
		die(phl, t_rel);
	pthread_mutex_lock(phl->inf->printmutex);
	if (phl->philo->need_eat == 0)
		return ;
	printf("\n \033[1;34m [%ld] \033[0m", t_rel);
	printf("El filósofo numero: \033[1;33m%d\033[0m", phl->philo->name);
	if (0 == ft_strcmp("comer", act))
		printf("\033[1;32m esta comiendo \033[0m \n");
	if (0 == ft_strcmp("dormir", act))
		printf(" \033[1;32m esta durmiendo \033[0m \n");
	if (0 == ft_strcmp("uso", act))
		printf(" uso \033[1;32m %s \033[0m \n", ob_con);
	if (0 == ft_strcmp("soltar", act))
		printf(" solto\033[1;32m %s \033[0m \n", ob_con);
	if (0 == ft_strcmp("pensar", act))
	{
		printf(" esta \033[1;32m pensando \033[0m");
/* 		if (0 == ft_strcmp("limitado", ob_con)) */
		printf(" quedan\033[1;32m %d \033[0m comidas\n", phl->philo->need_eat);
	}
	printf("filosos llenos?? %d/%d\n", phl->inf->fully, phl->inf->nph);
	printf("tiempo real = [%ld]\n", t_rel);
	pthread_mutex_unlock(phl->inf->printmutex);
}

void	ft_exit(char *texto, int fd)
{
	write(fd, texto, ft_strlen(texto));
	exit(2);
}

void	ft_fully(t_list *phl)
{
	phl->inf->fully++;
	phl->philo->need_eat--;
}
/* 
void	ft_hand(t_list *phl, long int t_real)
{
	prin(t_real, phl, "tenedor del pana", "uso");
	phl->philo->need_eat--;
	prin(t_real, phl, "", "comer");
	usleep(phl->inf->t_eat);
	t_real = realtime(phl, "restore");
	prin(t_real, phl, "su tenedor", "soltar");
	pthread_mutex_unlock(phl->philo->mutex);
// 	phl->philo->boolmtx = 0;
	pthread_mutex_unlock(phl->next->philo->mutex);
	phl->next->philo->boolmtx = 0;
	prin(t_real, phl, "tenedor del pana", "soltar");
// 	phl->next->philo->boolmtx = 0;
} */

void	die(t_list	*list, int x)
{
	printf("El filoso n [%d] ha muerto\n", list->philo->name);
	printf("el tiempo de muerte es : %d\n", x);
	pthread_mutex_destroy(list->philo->mutex);
	ft_exit("un filosofo a muerto..", 1);
	exit(1);
}
