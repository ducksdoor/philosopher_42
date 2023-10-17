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

t_list	*create_list_ph(char **argv, t_list *phl, t_inf *inf)
{
	t_list			*philo;
	t_list			*xaus;
	int				x;

	x = 1;
	init(phl, argv, x, inf);
	while (x < ft_atoi(argv[1]))
	{
		x++;
		philo = malloc(sizeof(t_list));
		if (!philo)
			return (NULL);
		init(philo, argv, x, inf);
		ft_lstadd_back(&phl, philo);
	}
	xaus = ft_lstlast(phl);
	xaus->next = philo;
	return (phl);
}

int	main(int argc, char **argv)
{
	t_inf			*inf;
	t_list			*phl;
	pthread_mutex_t	*printmutex;
	int				x;

	segurity(argc, argv);
	printmutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(printmutex, NULL) != 0)
		ft_exit("no se creó un hilo", 2);
	inf = malloc(sizeof(t_inf));
	if (!inf)
		ft_exit("error malogarral", 2);
	init_inf(inf, argv, printmutex);
	x = 1;
	phl = malloc(sizeof(t_list));
	if (!phl)
		ft_exit("error malogarral", 2);
	phl = create_list_ph(argv, phl, inf); //aqui estas trabajando
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(phl->philo->thread, NULL);
		phl = phl->next;
	}
	ft_exit("\nEl programa se terminó con exito, todos los filos comieron\n", 1);
}

/* to do

---->>>>>>>> limpieza de hilos cuando los filosofos mueren
---->>>>> filosofo que se esperan entre si cuando acaban de comer
--->>>> limpieza de hilos cuando se acaban l comida


---> leaks? entender como se cierra todo sin leaks

---> Cerrar todos los hilos desde uno de ellos...
---> 
---> 
--->*/
