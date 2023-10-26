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

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst)
	{
		while (lst->next)
				lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	temp = ft_lstlast(*lst);
	if (temp)
		temp->next = new;
	else
		*lst = new;
}

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
		pthread_mutex_lock(inf->printmutex);
		ft_lstadd_back(phl, philo);
		pthread_mutex_unlock(inf->printmutex);
	}
	pthread_mutex_lock(inf->printmutex);
	ft_lstadd_back(&philo, *phl);
	pthread_mutex_unlock(inf->printmutex);
/* 	xaus = ft_lstlast(*phl);
	xaus->next = *phl; */
	//return (phl);
}

int	main(int argc, char **argv)
{
	t_inf			*inf;
	t_list			*phl;
	pthread_mutex_t	*printmutex;
	int				x;

	segurity(argc, argv);
	printmutex = malloc(sizeof(pthread_mutex_t)); // proteger malloc
	if (pthread_mutex_init(printmutex, NULL) != 0)
		ft_exit("no se creó un hilo", 2);
	inf = malloc(sizeof(t_inf));
	if (!inf)
		ft_exit("error malogarral", 2);
	init_inf(inf, argv, printmutex);
	x = 1;
	phl = NULL;
	create_list_ph(argv, &phl, inf);
	while (x <= ft_atoi(argv[1]))
	{
		pthread_join(phl->philo->thread, NULL);
		phl = phl->next;
		x++;
	}
	ft_data_clean(phl);
	ft_clean(phl);
}

/* to do

-leak: 1 por cada filo que creas (poniendo un exit se resuelve todo pero claro, una pena que no se puede )
----te vas a inflar a frees
-te ha explotado con 200 filosofos
-no se mueren, hay que retocar eso...! y retocar la funcion en general



---->>>>>>>> limpieza de hilos cuando los filosofos mueren
---->>>>> Ultimo mensaje, todos los filosofos han comido.
--->>>> limpieza de hilos cuando se acaban l comida


---> leaks? entender como se cierra todo sin leaks

---> Cerrar todos los hilos desde uno de ellos...
---> 
---> 
--->*/
