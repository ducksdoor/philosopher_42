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

typedef struct s_inf
{
	int				born;
	int				fully;
	int				nph;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	struct timeval	start;
	pthread_mutex_t	*stopmutex;
	int				death;
}					t_inf;

typedef struct s_list
{
	struct s_inf	*inf;
	struct s_philo	*philo;
	struct s_list	*next;
	struct s_time	*clock;
}				t_list;

typedef struct s_time
{
	struct timeval	end;
	struct timeval	aux;
	int				t_juego;
}				t_time;

typedef struct s_philo
{
	int				name;
	pthread_t		thread;
	pthread_mutex_t	*mutex;
	int				need_eat;
}				t_philo;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	create_list_ph(char **argv, t_list **phl, t_inf *inf);
void	init(t_list *phl, char **argv, int x, t_inf *inf);
void	init_inf(t_inf *inf, char **argv, pthread_mutex_t *stopmutex);
int		segurity(int argc, char **argv);
void	segurity_for_close(int x, char **argv, t_list *phl);
void	ft_wait_for_start(t_list *phl);
void	ft_wait_for_finish(t_list *phl, long t_real);
int		ft_atoi(char *str);
int		ft_strlen(char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exit(char *texto);
void	ft_crono(void);
void	*thread_ft(void *arg);
void	ft_select(t_list *phl, long int t_real);
void	eat(t_list *x, long t_real);
void	die(t_list	*phl, long t_real);
long	ft_time(struct timeval start, struct timeval end);
long	realtime(t_list *phl, char *status);
void	prin(long t_rel, t_list *phl, char *act);
void	ft_clean(t_list *phl);
void	ft_data_clean(t_list *phl);
void	ft_fully(t_list *phl);

#endif