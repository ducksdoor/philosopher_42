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

void	create_list_ph(char **argv, t_list **phl, t_inf *inf)
{
	t_list			*philo;
	t_list			*xaus;
	int				x;

	philo = NULL;
	xaus = NULL;
	x = 1;
	*phl = malloc(sizeof(t_list));
	init(*phl, argv, x, inf);
	while (x < ft_atoi(argv[1]))
	{
		x++;
		philo = malloc(sizeof(t_list));
		if (!philo)
			return ;
		init(philo, argv, x, inf);
		pthread_mutex_lock(inf->stopmutex);
		ft_lstadd_back(phl, philo);
		pthread_mutex_unlock(inf->stopmutex);
	}
	pthread_mutex_lock(inf->stopmutex);
	ft_lstadd_back(&philo, *phl);
	pthread_mutex_unlock(inf->stopmutex);
}

static t_list	*first_init_all(char **argv)
{
	t_inf			*inf;
	t_list			*phl;
	pthread_mutex_t	*stopmutex;

	stopmutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(stopmutex, NULL) != 0)
		printf("no se creó un hilo");
	inf = malloc(sizeof(t_inf));
	if (!inf)
		printf("error malogarral");
	init_inf(inf, argv, stopmutex);
	phl = NULL;
	create_list_ph(argv, &phl, inf);
	return (phl);
}

int	main(int argc, char **argv)
{
	t_list	*phl;
	int		bool_for_ok;

	bool_for_ok = segurity(argc, argv);
	if (bool_for_ok == 1)
	{
		phl = first_init_all(argv);
		if (phl)
		{
			ft_create_thread(phl);
			segurity_for_close(bool_for_ok, phl);
		}
	}
}

/* to do

------>>>>>> 

------>>>>>> proteger maloc, pero sin exit no va a crear problemas despues!?

---->>>>>>>> Preguntar por el multiplicador de tiempo. modificar para no multiplicar por mil
---->>>>>>>> los filosofos en modo infinito se quedan bloqueados.
-			--> en modo infinito tarda mucho en cerrar.
--->>>>>>>>> crear usleep y comprobar muerte en sleep. (pasaria lo mismo si tarda mas en comer que el tiempo de morirse?)




---->>>>>>>> 
---> 
---> 
---> 
--->*/
