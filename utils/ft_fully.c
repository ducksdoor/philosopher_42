/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fully.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lortega- <lortega-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:46:01 by lortega-          #+#    #+#             */
/*   Updated: 2023/11/02 22:46:05 by lortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_fully(t_list *phl)
{
	pthread_mutex_lock(phl->inf->stopmutex);
	phl->inf->fully++;
	pthread_mutex_unlock(phl->inf->stopmutex);
	phl->philo->need_eat--;
}
