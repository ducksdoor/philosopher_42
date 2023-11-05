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

#include "../philosophers.h"

int	segurity(int argc, char **argv)
{
	int	x;

	x = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Número incorrecto de argumentos\n");
		return (2);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Nº de filosofos maximo 200\n");
		return (2);
	}
	while (x < argc)
	{
		if (ft_atoi(argv[x]) <= 0)
		{
			printf("Valor incorrecto\n");
			return (2);
		}
		x++;
	}
	return (1);
}

void	segurity_for_close(int x, t_list *phl)
{
	while (x <= phl->inf->nph && phl->inf->nph > 1)
	{
		pthread_join(phl->philo->thread, NULL);
		phl = phl->next;
		x++;
	}
	if (phl->inf->nph == 1)
		pthread_join(phl->philo->thread, NULL);
	ft_clean(phl);
}

void	segurity_for_finish(t_list *phl, int bool_for_dead, long t_real)
{
	while (bool_for_dead == 0)
	{
		pthread_mutex_lock(phl->inf->stopmutex);
		if (phl->inf->fully >= phl->inf->nph)
		{
			bool_for_dead = 1;
			phl->inf->death++;
		}
		if (phl->inf->death != 0)
			bool_for_dead = 1;
		pthread_mutex_unlock(phl->inf->stopmutex);
		if (bool_for_dead == 1)
			return ;
		if (bool_for_dead == 0)
			ft_diner(phl, t_real);
	}
}
