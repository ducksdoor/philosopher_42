/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:40:42 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/24 15:40:45 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_list
{
	struct s_philo	*philo;
	struct s_list	*next;
}					t_list;

typedef struct s_philo
{
	int			name;
	pthread_t	thread;
	int			fork;

	int			n_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_times_each_philosopher_must_eat;
}				t_philo;

void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*create_list_filo(int argc, char **argv);
int			main(int argc, char **argv);
void		init(t_list *philo_list, int argc, char **argv, int x);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
void		ft_exit(char *texto);
void		ft_crono(void);
void		*thread_ft(void *arg);
void		showme(t_list *list);


/* void	showme(t_list *list, char *a); */
#endif