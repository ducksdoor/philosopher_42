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
		pthread_mutex_lock(inf->stopmutex);
		ft_lstadd_back(phl, philo);
		pthread_mutex_unlock(inf->stopmutex);
	}
	pthread_mutex_lock(inf->stopmutex);
	ft_lstadd_back(&philo, *phl);
	pthread_mutex_unlock(inf->stopmutex);
}

int	main(int argc, char **argv)
{
	t_inf			*inf;
	t_list			*phl;
	pthread_mutex_t	*stopmutex;
	int				x;

	x = segurity(argc, argv);
	if (x == 1)
	{
		stopmutex = malloc(sizeof(pthread_mutex_t)); // proteger malloc
		if (pthread_mutex_init(stopmutex, NULL) != 0)
			ft_exit("no se creó un hilo");
		inf = malloc(sizeof(t_inf));
		if (!inf)
			ft_exit("error malogarral");
		init_inf(inf, argv, stopmutex);
		phl = NULL;
		create_list_ph(argv, &phl, inf);
		segurity_for_close(x, argv, phl);
	}
}

/* to do



---->>>>>>>> solo filosoofo que pasa? preguntar porque para mi esta bien pero porsiacaso.
---->>>>>>>> Preguntar por el multiplicador de tiempo por la misma razón que la de los filos.
---->>>>>>>> limpieza de hilos cuando los filosofos mueren porque da un pequeño fallo...
------------------> leaks tienes un par porque liberas de mas!
---->>>>>>>> los filosofos en modo infinito se quedan bloqueados.




---> 
---> 
---> 
--->*/
