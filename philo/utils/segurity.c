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

static int	ft_isdigit(char *argvx)
{
	int	x;

	x = 0;
	while (argvx[x] == 32)
		x++;
	if (argvx[x] == 43)
		x++;
	while (argvx[x] != '\0')
	{
		if (argvx[x] >= 48 && argvx[x] <= 57)
			x++;
		else
			return (0);
	}
	return (1);
}

int	segurity(int argc, char **argv)
{
	int	x;
	int	bool;

	x = 1;
	if (argc != 5 && argc != 6)
	{
		ft_putstr("Incorrect number of arguments.");
		return (2);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		ft_putstr("Number of philosophers maximum 200.");
		return (2);
	}
	while (x < argc)
	{
		bool = ft_isdigit(argv[x]);
		if (ft_atoi(argv[x]) <= 0 || bool == 0)
		{
			ft_putstr("incorrect value.");
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

void	segurity_for_finish(t_list *phl, int bool_for_dead)
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
			ft_diner(phl);
	}
}
