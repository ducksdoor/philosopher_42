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

t_list	*create_list_filo(int argc, char **argv)
{
	int				x;
	t_list			*filolist;
	t_list			*philo;
	t_list			*xaus;

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
	xaus = ft_lstlast(filolist);
	xaus->next = filolist;
	return (filolist);
}

void leaks(void)
{
	system("leaks -q philo"); 
}
//	atexit(leaks);

int	main(int argc, char **argv)
{
	t_list			*p_list;
	int				x;

	if (argc != 5 && argc != 6)
		ft_exit("Número incorrecto de argumentos", 2);
	if (argc == 6 && argv[5] <= 0)
		ft_exit("Número de veces de comer erroneo", 2);
	p_list = create_list_filo(argc, argv);
	x = 1;
	//showme(p_list);
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(p_list->philo->thread, NULL);
		p_list = p_list->next;
	}
	ft_exit("El programa ha terminado", 1);
}

/* to do
----quiza dividir el init en tres pasos o al menos que la función que crea los procesos sea distinta que la de los tenedores


---->gestionar que los filosofos entren a comer hasta el infinito si no esta el numero opcional
--->Rebajar  en lineas la función de los hilos, muy importante.
--->quitar los printf

---> que no sea negativo el numero que entra. 
	---> los filosofos tienen que ser capaces de acceder al tenedor del siguiente, 
---> Crear los tenedores
---> Porque el tiempo que se da no es preciso?
---> leaks? entender como se cierra todo sin leaks
---> Cerrar todos los hilos desde uno de ellos...
---> 
---> 
--->*/
