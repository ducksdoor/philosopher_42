/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:40:32 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/24 15:40:35 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_list	*create_list_filo(char **argv, pthread_mutex_t *printmtx)
{
	int				x;
	t_list			*phl;
	t_list			*philo;
	t_list			*xaus;

	phl = malloc(sizeof(t_list));
	if (!phl)
		return (NULL);
	x = 2;
	init(phl, argv, (x -1), printmtx);
	while (x <= ft_atoi(argv[1]))
	{
		philo = malloc(sizeof(t_list));
		if (!philo)
			return (NULL);
		init(philo, argv, x, printmtx);
		ft_lstadd_back(&phl, philo);
		x++;
	}
	xaus = ft_lstlast(phl);
	xaus->next = phl;
	return (phl);
}

/* void leaks(void)
{
	system("leaks -q philo"); 
} */
//	atexit(leaks);

int	main(int argc, char **argv)
{
	t_list			*p_list;
	pthread_mutex_t	*printmutex;
	int				x;
	int				finish;

	segurity(argc, argv);
	printmutex = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(printmutex, NULL) != 0)
		ft_exit("no se creó un hilo", 2);
	p_list = create_list_filo(argv, printmutex);
	x = 1;
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(p_list->philo->thread, NULL);
		p_list = p_list->next;
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
