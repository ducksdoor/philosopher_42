/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:39:38 by lortega-          #+#    #+#             */
/*   Updated: 2023/09/25 20:39:43 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_wait_for_finish(t_list *phl, long t_real)
{
	int	x;

	x = 0;
	while (1)
	{
		ft_select(phl, t_real);
		pthread_mutex_lock(phl->inf->printmutex);
		if (phl->inf->fully == phl->inf->nph)
			x = 1;
		pthread_mutex_unlock(phl->inf->printmutex);
		if (x == 1)
			return ;
	}
}

void	ft_wait_for_start(t_list *phl)
{
	int	x;

	while (1)
	{
		pthread_mutex_lock(phl->inf->printmutex);
		x = 0;
		if (phl->inf->born == phl->inf->nph)
			x = 1;
		pthread_mutex_unlock(phl->inf->printmutex);
		if (x == 1)
			return ;
		usleep(50);
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int		dif;
	size_t	x;

	dif = 0;
	x = 0;
	while (!dif && (s1[x] != '\0') && (s2[x] != '\0'))
	{
		dif = (unsigned char)s1[x] - (unsigned char)s2[x];
		x++;
	}
	if (!dif && (s1[x] == '\0' || s2[x] == '\0'))
		dif = (unsigned char)s1[x] - (unsigned char)s2[x];
	return (dif);
}

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
