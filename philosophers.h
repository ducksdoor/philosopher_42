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
# include <pthread.h>
# include <sys/time.h>

typedef struct s_list
{
	struct s_philo	*philo;
	struct s_list	*next;
/* 	int				start_time; */
}					t_list;

typedef struct s_philo
{
	int				name;
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	int				boolmutex;
	int				mute_fork;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times_must_eat;
}				t_philo;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*create_list_filo(int argc, char **argv);
int		main(int argc, char **argv);
void	init(t_list *philo_list, int argc, char **argv, int x);
int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	ft_exit(char *texto, int fd);
void	ft_crono(void);
void	*thread_ft(void *arg);
void	*die(t_list	*list, int x);
void	showme(t_list *list);

#endif