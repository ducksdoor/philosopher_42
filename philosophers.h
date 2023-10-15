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

/* typedef struct s_data
{
	pthread_mutex_t		mutexprint;
}	t_data;
 */
typedef struct s_list
{
	struct s_philo	*philo;
	struct s_list	*next;
	pthread_mutex_t	*printmutex;
	int				nph;
	struct s_time	*clock;
}				t_list;

typedef struct s_time
{
	struct timeval	start;
	struct timeval	end;
	struct timeval	aux;
	int				t_juego;
}				t_time;

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
	int				need_eat;
}				t_philo;

t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*create_list_filo(char **argv, pthread_mutex_t *printmtx);
void		init(t_list *phl, char **argv, int x, pthread_mutex_t *printmtx);
void		segurity(int argc, char **argv);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_exit(char *texto, int fd);
void		ft_crono(void);
void		*thread_ft(void *arg);
void		die(t_list	*list, int x);
void		eat(t_list *x, long t_real);
long		ft_time(struct timeval start, struct timeval end);
long int	realtime(t_list *phl, char *status);
void		ft_hand(t_list *phl, char *action, long int t_real);
void		lookprint(long int t_real, t_list *phl, char *objeto, char *action);

void		showme(t_list *list);

#endif