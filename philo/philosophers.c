/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:40:32 by lortega-          #+#    #+#             */
/*   Updated: 2023/10/16 22:51:49 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	protect_create_list_phl(t_list *phl, int x, t_inf *inf)
{
	int	y;

	y = 1;
	free(inf);
	while (y < x)
	{
		pthread_mutex_destroy(phl->philo->mutex);
		free(phl->philo);
		free(phl->clock);
		if (phl->next)
			phl = phl->next;
		y++;
	}
	free(phl);
}

static void	create_list_ph(char **argv, t_list **phl, t_inf *inf)
{
	t_list			*philo;
	int				x;

	x = 1;
	*phl = malloc(sizeof(t_list));
	if (!phl)
	{
		ft_select_free("The first philosopher was not created.", inf, phl);
		return ;
	}
	init(*phl, argv, x, inf);
	while (x++ < ft_atoi(argv[1]) && phl)
	{
		philo = malloc(sizeof(t_list));
		init(philo, argv, x, inf);
		if (!philo)
		{
			protect_create_list_phl(*phl, x, inf);
			return ;
		}
		ft_lstadd_back(phl, philo);
	}
	ft_lstadd_back(&philo, *phl);
}

int	main(int argc, char **argv)
{
	t_inf			*inf;
	t_list			*phl;
	pthread_mutex_t	*stopmutex;
	int				bool_for_ok;

	bool_for_ok = segurity(argc, argv);
	stopmutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(stopmutex, NULL) != 0)
		ft_free("Stopmutex thread was not created.", stopmutex);
	inf = malloc(sizeof(t_inf));
	if (!inf)
		ft_select_free("The t-list inf was not created.", stopmutex, inf);
	if (bool_for_ok == 1 && stopmutex && inf)
	{
		phl = NULL;
		init_inf(inf, argv, stopmutex);
		create_list_ph(argv, &phl, inf);
		if (!phl)
		{
			ft_free("", stopmutex);
			return (2);
		}
		ft_create_thread(phl);
		segurity_for_close(bool_for_ok, phl);
	}
}
