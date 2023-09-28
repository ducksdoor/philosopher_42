/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:57:12 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/28 20:57:22 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* 
struct timeval	crono_trucado(start)
{

}

 */

void	*thread_ft(void *arg)
{
	struct timeval	start;
	struct timeval	end;
/* 	struct timeval	result; */
	t_list	*x;
	int		name;
	int		turno;
	int		tiempo_pasado;

	gettimeofday(&start, NULL);

	x = arg;
	name = x->philo->name;
	tiempo_pasado = 0;
	while (x->philo->n_times_each_philosopher_must_eat > 0)
	{
		gettimeofday(&end, NULL);
		turno = (end.tv_usec - start.tv_usec);
		//printf("%d\n", turno);
		if (turno >= x->philo->time_to_die)
		{
			printf("he muerto");
			exit(1);
		}
			//Esto hace que "coma" cada x tiempo.
		else if (turno >= x->philo->time_to_eat)
		{
			printf("he comido\n");
			/* tiempo_pasado = tiempo_pasado + x->philo->time_to_eat; */
			gettimeofday(&start, NULL);
			printf("el tiempo de muerte es : %d\n", turno);
		}
		usleep(111);
		printf("[%d]Soy el filosofo %d, me quedan %d comidas y Estoy vivo aun !\n",turno, name, x->philo->n_times_each_philosopher_must_eat);
		x->philo->n_times_each_philosopher_must_eat--;
	}
	exit(1);
}
