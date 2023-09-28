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
t_list *create_list_filo(int argc, char **argv)
{
	int		x;
	t_list	*filolist;
	t_list	*philo;

	filolist = malloc(sizeof(t_list));
	if (!filolist)
		return (NULL);
	x = 2;
	init(filolist, argc, argv, (x -1));
	while (x <= ft_atoi(argv[1]))
	{
		philo = malloc(sizeof(t_list));
		if (!philo)
			return (NULL);
		init(philo, argc, argv, x);
		ft_lstadd_back(&filolist, philo);
		x++;
	}
	x = 1;
	return (filolist);
}

int	main(int argc, char **argv)
{
	t_list		*p_list;
/* 	t_list		*aux; */
	int			x;

	if (argc != 5 && argc != 6)
		ft_exit("Número incorrecto de argumentos");
	p_list = create_list_filo(argc, argv);
	x = 1;
	showme(p_list);
	ft_crono();
/* 	aux = *p_list; */
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(p_list->philo->thread, NULL);
		p_list = p_list->next;
	}
}


/* to do 
---> que no sea negativo el numero que entra. 
	---> los filosofos tienen que ser capaces de acceder al tenedor del siguiente, 
---> Crear los tenedores
---> Porque el tiempo que se da no es preciso?
---> leaks? entender como se cierra todo sin leaks
---> Cerrar todos los hilos desde uno de ellos...
---> 
---> 
--->*/
