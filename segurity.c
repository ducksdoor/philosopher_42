/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segurity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/28 20:57:22 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	segurity(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Número incorrecto de argumentos");
		return (2);
	}
	while (x < argc)
	{
		if (ft_atoi(argv[x]) <= 0)
		{
			printf("Valor incorrecto");
			return (2);
		}
		x++;
	}
	return (1);
}

void	segurity_for_close(int x, char **argv, t_list *phl)
{
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(phl->philo->thread, NULL);
		phl = phl->next;
		x++;
	}
	ft_data_clean(phl);
	ft_clean(phl);
}

void	ft_wait_for_finish(t_list *phl, long t_real)
{
	int	x;

	x = 0;
	while (1)
	{
		ft_select(phl, t_real);
		pthread_mutex_lock(phl->inf->stopmutex);
		if (phl->inf->fully == phl->inf->nph)
		{
			x = 1;
			phl->inf->death++;
		}
		pthread_mutex_unlock(phl->inf->stopmutex);
		if (x == 1)
			return ;
	}
}



void	ft_wait_for_start(t_list *phl)
{
	int	x;

	while (1)
	{
		pthread_mutex_lock(phl->inf->stopmutex);
		x = 0;
		if (phl->inf->born == phl->inf->nph)
			x = 1;
		pthread_mutex_unlock(phl->inf->stopmutex);
		if (x == 1)
			return ;
		usleep(25);
	}
}
