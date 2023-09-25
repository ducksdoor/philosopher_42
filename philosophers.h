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

typedef struct s_philo
{
	int	n_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_each_philosopher_must_eat;
}				t_philo;

int		main(int argc, char **argv);
void	init(t_philo *philo, int argc, char **argv);
int		ft_atoi(char *str);
int		ft_strlen(char *s);
void	ft_exit(char *texto);
void	ft_crono(void);
void	*my_thread_function(void *arg);
#endif