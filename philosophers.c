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
	void	*x;

	x = arg;
	while (1)
	{
		usleep(500000);
		printf("Estoy vivo aun !\n");
	}

}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	pthread_t	my_thread;

	if (argc != 5 && argc != 6)
		ft_exit("Número incorrecto de argumentos");
	philo = malloc(sizeof(t_philo));
	init(philo, argc, argv);
	pthread_create(&my_thread, NULL, my_thread_function, NULL);
	ft_crono();
	pthread_join(my_thread, NULL);

	printf("El hilo ha terminado.\n");
/* 	printf("%d", philo->n_philosophers); */
}
