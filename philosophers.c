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


void	*my_thread_function(void *arg)
{
	t_list	*x;
	int		name;

	x = arg;
	name = x->philo->name;
	printf("creo el tenedor numero %d\n", name);
	while (x->philo->n_times_each_philosopher_must_eat >= 0)
	{
		usleep(500000);
		printf("Soy el filosofo %d Estoy vivo aun !\n", name);
		x->philo->n_times_each_philosopher_must_eat--;
	}
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list		*p_list;

	pthread_t	my_thread[100];
	int			x;

	if (argc != 5 && argc != 6)
		ft_exit("Número incorrecto de argumentos");

	p_list = malloc(sizeof(t_list));
	init(p_list, argc, argv);
	x = 1;
		//Este bloque es para los bucles
	while (x <= ft_atoi(argv[1]))
	{
		if (0 != pthread_create(&my_thread[x], NULL, my_thread_function, p_list))
			ft_exit("error en la creación del hilo");
		x++;
		p_list->philo->name++;
		usleep(1);
	}
	ft_crono();
/* 	pthread_join(my_thread, NULL); */

	printf("El hilo ha terminado.\n");
/* 	printf("%d", philo->n_philosophers); */
}


/* to do 
---> que no sea negativo el numero que entra. 
---> Preparar la función showme para reciclarla, ahora es la del push swap
---> Meter y usar funciones relacionadas con listas como crear nodos
	---> la lista tiene que ser circular, el ultimo tendra que apuntar al primero
		lo de arriba es dando por supuesto que vas a crear un tenedor por nodo
---> Crear los tenedores
---> Porque el tiempo que se da no es preciso?
---> leaks? entender como se cierra todo sin leaks
---> Cerrar todos los hilos desde uno de ellos...
---> 
--->
--->*/
